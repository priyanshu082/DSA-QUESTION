package WasteFiles;
import javax.swing.*;
import java.awt.*;
import java.util.concurrent.*;
import java.util.Random;

public class DiningPhilosophersGUI extends JFrame {
    private static int NUM_PHILOSOPHERS;
    private static final int RADIUS = 200;
    private static final int CIRCLE_RADIUS = 20;
    private static Semaphore[] forks;
    private static Semaphore mutex = new Semaphore(1);
    private static Philosopher[] philosophers;

    public DiningPhilosophersGUI(int numPhilosophers) {
        NUM_PHILOSOPHERS = numPhilosophers;
        setTitle("Dining Philosophers Problem");
        setSize(800, 800); // Increased size for better visibility
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setResizable(false); // Prevent resizing
        getContentPane().setBackground(Color.DARK_GRAY); // Changed background color
        setVisible(true);

        forks = new Semaphore[NUM_PHILOSOPHERS];
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            forks[i] = new Semaphore(1);
        }

        philosophers = new Philosopher[NUM_PHILOSOPHERS];
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            philosophers[i] = new Philosopher(i);
            new Thread(philosophers[i]).start();
        }
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            double angle = 2 * Math.PI * i / NUM_PHILOSOPHERS;
            int x = (int) (400 + RADIUS * Math.cos(angle)); // Center adjusted
            int y = (int) (400 + RADIUS * Math.sin(angle)); // Center adjusted

            g2d.setColor(philosophers[i].isEating() ? Color.YELLOW : Color.LIGHT_GRAY); // Changed colors
            g2d.fillOval(x - CIRCLE_RADIUS, y - CIRCLE_RADIUS, CIRCLE_RADIUS * 2, CIRCLE_RADIUS * 2);

            g2d.setColor(Color.WHITE); // Changed text color
            String state = philosophers[i].isEating() ? "Eating" : "Thinking";
            g2d.drawString("Philosopher " + (i + 1) + ": " + state, x - 30, y + 30); // Adjusted text position

            if (philosophers[i].isEating()) {
                int next = (i + 1) % NUM_PHILOSOPHERS;
                g2d.drawString("Using Forks: " + (i + 1) + " and " + (next + 1), x - 30, y + 50); // Adjusted text position
            }

            int next = (i + 1) % NUM_PHILOSOPHERS;
            g2d.setColor(forks[i].availablePermits() == 1 && forks[next].availablePermits() == 1 ? Color.WHITE : Color.RED); // Changed color logic
            g2d.drawLine(x, y, (int) (400 + RADIUS * Math.cos(2 * Math.PI * next / NUM_PHILOSOPHERS)),
                    (int) (400 + RADIUS * Math.sin(2 * Math.PI * next / NUM_PHILOSOPHERS))); // Center adjusted
        }
    }

    class Philosopher implements Runnable {
        private final int id;
        private boolean eating = false;

        public Philosopher(int id) {
            this.id = id;
        }

        public void run() {
            while (true) {
                think();
                try {
                    acquireForks();
                    eat();
                    releaseForks();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        private void think() {
            try {
                Thread.sleep(new Random().nextInt(2000) + 3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void acquireForks() throws InterruptedException {
            mutex.acquire(); 
            forks[id].acquire(); 
            forks[(id + 1) % NUM_PHILOSOPHERS].acquire(); 
            mutex.release();
        }

        private void eat() throws InterruptedException {
            eating = true;
            repaint();
            Thread.sleep(new Random().nextInt(2000) + 3000);
            eating = false;
            repaint();
        }

        private void releaseForks() {
            forks[id].release(); 
            forks[(id + 1) % NUM_PHILOSOPHERS].release(); 
        }

        public boolean isEating() {
            return eating;
        }
    }

    public static void main(String[] args) {
        String input = JOptionPane.showInputDialog("Enter the number of philosophers:");
        try {
            int numPhilosophers = Integer.parseInt(input);
            if (numPhilosophers < 2) {
                JOptionPane.showMessageDialog(null, "Number of philosophers must be at least 2.");
                return;
            }
            SwingUtilities.invokeLater(() -> new DiningPhilosophersGUI(numPhilosophers));
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Invalid input. Please enter a valid number.");
        }
    }
}