import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class ThoughtsDisplay extends JFrame {
    private JLabel thoughtLabel;
    private JButton nextThoughtButton;
    private JPanel thoughtPanel; // Added a JPanel for the thought display
    private String[] thoughts = {
            "Life is what happens when you're busy making other plans.",
            "The only limit to our realization of tomorrow will be our doubts of today.",
            "Success is not final, failure is not fatal: It is the courage to continue that counts."
    };

    private int currentThoughtIndex = 0;

    public ThoughtsDisplay() {
        // Set the title of the window
        super("Thoughts Display GUI");

        // Create components
        thoughtLabel = new JLabel(thoughts[currentThoughtIndex]);
        nextThoughtButton = new JButton("Next Thought");
        thoughtPanel = new JPanel(); // Create a panel for thought display

        // Set layout manager for the main frame
        setLayout(null);

        // Set layout manager for the thoughtPanel
        thoughtPanel.setLayout(null);

        // Add components to the thoughtPanel
        thoughtLabel.setBounds(10, 10, 520, 30); // Centered within thoughtPanel
        thoughtPanel.add(thoughtLabel);
        thoughtPanel.setBounds(40, 40, 540, 50); // Centered within the main frame
        thoughtPanel.setBackground(new Color(70, 130, 180)); // Darker blue color for thought display

        // Add components to the main frame
        nextThoughtButton.setBounds(180, 120, 200, 50); // Increased button size
        add(thoughtPanel);
        add(nextThoughtButton);

        // Set button and background colors
        updateButtonColor(); // Set initial color
        getContentPane().setBackground(new Color(30, 40, 50)); // Dark background color

        // Add action listener to the button
        nextThoughtButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Change the thought when the button is clicked
                currentThoughtIndex = (currentThoughtIndex + 1) % thoughts.length;
                thoughtLabel.setText(thoughts[currentThoughtIndex]);
            }
        });

        // Add mouse listener to the button for hover effect
        nextThoughtButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                nextThoughtButton.setBackground(new Color(255, 165, 0)); // Orange color on hover
            }

            @Override
            public void mouseExited(MouseEvent e) {
                updateButtonColor(); // Restore original color when not hovering
            }
        });

        // Set default close operation and size
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 250); // Adjusted window size
        setLocationRelativeTo(null); // Center the window
    }

    private void updateButtonColor() {
        nextThoughtButton.setBackground(new Color(255, 140, 0)); // Orange color
    }

    public static void main(String[] args) {
        // Create and show the GUI
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ThoughtsDisplay().setVisible(true);
            }
        });
    }
}
