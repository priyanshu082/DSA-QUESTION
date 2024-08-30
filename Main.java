import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Main extends JFrame {
    private static final int NODE_SIZE = 40;
    private final Queue<Node> queue = new LinkedList<>();
    private int nodeCounter = 0;
    private final ArrayList<Node> nodes = new ArrayList<>();
    private final ArrayList<Edge> edges = new ArrayList<>();
    private Node selectedNode = null;
    private boolean isTraversalRunning = false;
    private JTextArea logArea; // New text area for logging

    public Main() {
        setTitle("Graph Traversal Visualization");
        setSize(800, 700); // Increased height to accommodate the log area
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        GraphPanel graphPanel = new GraphPanel();
        add(graphPanel, BorderLayout.CENTER);

        JPanel controlPanel = new JPanel();
        JButton addNodeBtn = new JButton("Add Node");
        JButton addEdgeBtn = new JButton("Add Edge");
        JButton deleteNodeBtn = new JButton("Delete Node");
        JButton startDfsBtn = new JButton("Start DFS");
        JButton startBfsBtn = new JButton("Start BFS");
        JButton resetButton = new JButton("Reset");
        

        controlPanel.add(addNodeBtn);
        controlPanel.add(addEdgeBtn);
        controlPanel.add(deleteNodeBtn);
        controlPanel.add(startDfsBtn);
        controlPanel.add(startBfsBtn);
        controlPanel.add(resetButton);
        add(controlPanel, BorderLayout.NORTH);

        // Create and add the log area
        logArea = new JTextArea(10, 50);
        logArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(logArea);
        add(scrollPane, BorderLayout.SOUTH);

        addNodeBtn.addActionListener(e -> graphPanel.addNode());
        addEdgeBtn.addActionListener(e -> graphPanel.addEdge());
        deleteNodeBtn.addActionListener(e -> graphPanel.deleteNode());
        startDfsBtn.addActionListener(e -> {
            if (!nodes.isEmpty() && !isTraversalRunning) {
                isTraversalRunning = true;
                new Thread(this::startDFS).start();
            }
        });
        startBfsBtn.addActionListener(e -> {
            if (!nodes.isEmpty() && !isTraversalRunning) {
                isTraversalRunning = true;
                new Thread(this::startBFS).start();
            }
        });
        resetButton.addActionListener(e->resetNodes());
    }

    private void startDFS() {
        resetNodes();
        logArea.setText(""); // Clear previous logs
        log("Starting DFS traversal...\n");
        Node startNode = getStartNode();
        if (startNode != null) {
            dfs(startNode);
        }
        log("DFS traversal completed.\n");
        isTraversalRunning = false;
    }

    private void startBFS() {
        resetNodes();
        logArea.setText(""); // Clear previous logs
        log("Starting BFS traversal...\n");
        Node startNode = getStartNode();
        if (startNode != null) {
            bfs(startNode);
        }
        log("BFS traversal completed.\n");
        isTraversalRunning = false;
    }

    private void resetNodes() {
        for (Node node : nodes) {
            node.setVisited(false);
        }
        repaint();
    }

    private Node getStartNode() {
        String startNodeLabel = JOptionPane.showInputDialog(this, "Enter the label of the starting node:");
        return nodes.stream()
                    .filter(node -> node.getLabel().equals(startNodeLabel))
                    .findFirst()
                    .orElseGet(() -> {
                        JOptionPane.showMessageDialog(this, "Invalid node label. Starting from the first node.");
                        return nodes.isEmpty() ? null : nodes.get(0);
                    });
    }

    private void dfs(Node node) {
        node.setVisited(true);
        log("Visiting node: " + node.getLabel() + "\n");
        repaint();
        sleep(1000);

        for (Edge edge : edges) {
            Node neighbor = null;
            if (edge.getFromNode() == node && !edge.getToNode().isVisited()) {
                neighbor = edge.getToNode();
            } else if (edge.getToNode() == node && !edge.getFromNode().isVisited()) {
                neighbor = edge.getFromNode();
            }
            if (neighbor != null) {
                dfs(neighbor);
            }
        }
    }

    private void bfs(Node startNode) {
        Queue<Node> bfsQueue = new LinkedList<>();
        bfsQueue.add(startNode);
        startNode.setVisited(true);
        log("Visiting node: " + startNode.getLabel() + "\n");

        while (!bfsQueue.isEmpty()) {
            Node node = bfsQueue.poll();
            repaint();
            sleep(1000);

            for (Edge edge : edges) {
                Node neighbor = null;
                if (edge.getFromNode() == node && !edge.getToNode().isVisited()) {
                    neighbor = edge.getToNode();
                } else if (edge.getToNode() == node && !edge.getFromNode().isVisited()) {
                    neighbor = edge.getFromNode();
                }
                if (neighbor != null) {
                    bfsQueue.add(neighbor);
                    neighbor.setVisited(true);
                    log("Visiting node: " + neighbor.getLabel() + "\n");
                }
            }
        }
    }

    private void sleep(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    private void log(String message) {
        SwingUtilities.invokeLater(() -> {
            logArea.append(message);
            logArea.setCaretPosition(logArea.getDocument().getLength());
        });
    }

    class GraphPanel extends JPanel {
        public GraphPanel() {
            addMouseListener(new MouseAdapter() {
                @Override
                public void mousePressed(MouseEvent e) {
                    if (!isTraversalRunning) {
                        selectOrAddNode(e.getX(), e.getY());
                    }
                }
            });
        }

        public void addNode() {
            JOptionPane.showMessageDialog(null, "Click anywhere on the panel to add a node.");
        }

        public void addEdge() {
            if (selectedNode != null) {
                JOptionPane.showMessageDialog(null, "Select another node to connect an edge.");
            } else {
                JOptionPane.showMessageDialog(null, "Select a node first to start creating an edge.");
            }
        }

        public void deleteNode() {
            if (selectedNode != null) {
                nodes.remove(selectedNode);
                queue.add(selectedNode);
                edges.removeIf(edge -> edge.getFromNode() == selectedNode || edge.getToNode() == selectedNode);
                selectedNode = null;
                repaint();
            } else {
                JOptionPane.showMessageDialog(null, "Select a node to delete.");
            }
        }

        private void selectOrAddNode(int x, int y) {
            for (Node node : nodes) {
                if (node.contains(x, y)) {
                    if (selectedNode == null) {
                        selectedNode = node;
                        node.setSelected(true);
                    } else {
                        if (selectedNode != node) {
                            edges.add(new Edge(selectedNode, node));
                        }
                        selectedNode.setSelected(false);
                        selectedNode = null;
                    }
                    repaint();
                    return;
                }
            }
            if (queue.isEmpty()) {
                nodes.add(new Node(x, y, "N" + nodeCounter++));
            } else {
                Node recycledNode = queue.poll();
                recycledNode.setX(x);
                recycledNode.setY(y);
                recycledNode.setVisited(false);
                recycledNode.setSelected(false);
                nodes.add(recycledNode);
            }
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            for (Edge edge : edges) {
                Node fromNode = edge.getFromNode();
                Node toNode = edge.getToNode();
                g.setColor(Color.BLACK);
                g.drawLine(fromNode.getX(), fromNode.getY(), toNode.getX(), toNode.getY());
            }

            for (Node node : nodes) {
                if (node.isVisited()) {
                    g.setColor(Color.BLUE);
                } else if (node.isSelected()) {
                    g.setColor(Color.GREEN);
                } else {
                    g.setColor(Color.YELLOW);
                }
                g.fillOval(node.getX() - NODE_SIZE / 2, node.getY() - NODE_SIZE / 2, NODE_SIZE, NODE_SIZE);
                g.setColor(Color.BLACK);
                g.drawString(node.getLabel(), node.getX() - 10, node.getY() - NODE_SIZE / 2 - 5);
            }
        }
    }

    static class Node {
        private int x, y;
        private final String label;
        private boolean visited;
        private boolean selected;

        public Node(int x, int y, String label) {
            this.x = x;
            this.y = y;
            this.label = label;
            this.visited = false;
            this.selected = false;
        }

        public int getX() { return x; }
        public void setX(int x) { this.x = x; }
        public int getY() { return y; }
        public void setY(int y) { this.y = y; }
        public String getLabel() { return label; }
        public boolean isVisited() { return visited; }
        public void setVisited(boolean visited) { this.visited = visited; }
        public boolean isSelected() { return selected; }
        public void setSelected(boolean selected) { this.selected = selected; }
        public boolean contains(int x, int y) {
            return Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2)) <= NODE_SIZE / 2.0;
        }
    }

    static class Edge {
        private final Node fromNode, toNode;

        public Edge(Node fromNode, Node toNode) {
            this.fromNode = fromNode;
            this.toNode = toNode;
        }

        public Node getFromNode() { return fromNode; }
        public Node getToNode() { return toNode; }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Main().setVisible(true));
    }
}