import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class ConvexHullVisualizer extends JPanel {
    private final ArrayList<Point> points = new ArrayList<>();
    private ArrayList<Point> hull = new ArrayList<>();

    public ConvexHullVisualizer() {
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                points.add(new Point(e.getX(), e.getY()));
                computeConvexHull();
                repaint();
            }
        });
    }

    private void computeConvexHull() {
        hull.clear();
        if (points.size() < 3) {
            hull.addAll(points);
            return;
        }

        // Find the lowest point (or leftmost if tie)
        Point minYPoint = Collections.min(points, Comparator.comparingInt((Point p) -> p.y).thenComparingInt(p -> p.x));

        // Sort points by polar angle with respect to minYPoint
        java.util.List<Point> sortedPoints = new ArrayList<>(points);
        sortedPoints.sort((a, b) -> {
            int orientation = crossProduct(minYPoint, a, b);
            if (orientation == 0) {
                return Double.compare(minYPoint.distance(a), minYPoint.distance(b));
            }
            return -Integer.compare(orientation, 0);
        });

        // Apply Graham's scan
        Stack<Point> stack = new Stack<>();
        for (Point p : sortedPoints) {
            while (stack.size() > 1 && crossProduct(stack.get(stack.size() - 2), stack.peek(), p) <= 0) {
                stack.pop();
            }
            stack.push(p);
        }

        hull.addAll(stack);
    }

    private int crossProduct(Point a, Point b, Point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);

        // Draw all points
        for (Point p : points) {
            g.fillOval(p.x - 3, p.y - 3, 6, 6);
        }

        // Draw convex hull
        g.setColor(Color.RED);
        for (int i = 0; i < hull.size(); i++) {
            Point p1 = hull.get(i);
            Point p2 = hull.get((i + 1) % hull.size());
            g.drawLine(p1.x, p1.y, p2.x, p2.y);
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Convex Hull Visualizer");
        ConvexHullVisualizer panel = new ConvexHullVisualizer();
        frame.add(panel);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
