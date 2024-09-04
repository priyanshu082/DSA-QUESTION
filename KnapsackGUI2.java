import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

public class KnapsackGUI2 extends JFrame {

    private JTextField weightField;
    private JTextField profitField;
    private JTextField maxWeightField;
    private JTextArea resultArea;
    private JTextArea stepsArea;
    private int[][] memo;

    public KnapsackGUI2() {
        setTitle("Knapsack Problem Solver");
        setSize(600, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Input Panel
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(5, 2));

        inputPanel.add(new JLabel("Enter weights (comma separated):"));
        weightField = new JTextField();
        inputPanel.add(weightField);

        inputPanel.add(new JLabel("Enter profits (comma separated):"));
        profitField = new JTextField();
        inputPanel.add(profitField);

        inputPanel.add(new JLabel("Enter max capacity of knapsack:"));
        maxWeightField = new JTextField();
        inputPanel.add(maxWeightField);

        JButton zeroOneButton = new JButton("Calculate 0/1 Knapsack");
        zeroOneButton.addActionListener(new ZeroOneKnapsackActionListener());
        inputPanel.add(zeroOneButton);

        JButton fractionalButton = new JButton("Calculate Fractional Knapsack");
        fractionalButton.addActionListener(new FractionalKnapsackActionListener());
        inputPanel.add(fractionalButton);

        add(inputPanel, BorderLayout.NORTH);

        // Result Panel
        JPanel resultPanel = new JPanel();
        resultPanel.setLayout(new GridLayout(2, 1));

        resultArea = new JTextArea();
        resultArea.setEditable(false);
        resultPanel.add(new JScrollPane(resultArea));

        stepsArea = new JTextArea();
        stepsArea.setEditable(false);
        resultPanel.add(new JScrollPane(stepsArea));

        add(resultPanel, BorderLayout.CENTER);
    }

    private class ZeroOneKnapsackActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                String[] weightsStr = weightField.getText().split(",");
                String[] profitsStr = profitField.getText().split(",");
                int[] weights = Arrays.stream(weightsStr).mapToInt(Integer::parseInt).toArray();
                int[] profits = Arrays.stream(profitsStr).mapToInt(Integer::parseInt).toArray();
                int maxWeight = Integer.parseInt(maxWeightField.getText());

                int items = weights.length;

                memo = new int[items + 1][maxWeight + 1]; // Initialize memoization array
                for (int i = 0; i <= items; i++) {
                    for (int j = 0; j <= maxWeight; j++) {
                        memo[i][j] = -1;
                    }
                }

                stepsArea.setText(""); // Clear previous steps
                int zeroOneKnapsackProfit = _ZeroOneKnapsack(weights, profits, maxWeight, items);
                resultArea.setText("Total profit (0/1 Knapsack): " + zeroOneKnapsackProfit);

            } catch (Exception ex) {
                JOptionPane.showMessageDialog(KnapsackGUI2.this, "Invalid input! Please enter valid integers.");
            }
        }
    }

    private class FractionalKnapsackActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                String[] weightsStr = weightField.getText().split(",");
                String[] profitsStr = profitField.getText().split(",");
                int[] weights = Arrays.stream(weightsStr).mapToInt(Integer::parseInt).toArray();
                int[] profits = Arrays.stream(profitsStr).mapToInt(Integer::parseInt).toArray();
                int maxWeight = Integer.parseInt(maxWeightField.getText());

                int items = weights.length;

                stepsArea.setText(""); // Clear previous steps
                double fractionalKnapsackProfit = _fractionalKnapsack(weights, profits, maxWeight, items);
                resultArea.setText("Total profit (Fractional Knapsack): " + fractionalKnapsackProfit);

            } catch (Exception ex) {
                JOptionPane.showMessageDialog(KnapsackGUI2.this, "Invalid input! Please enter valid integers.");
            }
        }
    }

    private int _ZeroOneKnapsack(int[] weight, int[] profit, int maxWt, int items) {
        if (items == 0 || maxWt == 0)
            return 0;
        if (memo[items][maxWt] != -1)
            return memo[items][maxWt];
        if (weight[items - 1] <= maxWt) {
            int included = _ZeroOneKnapsack(weight, profit, maxWt - weight[items - 1], items - 1) + profit[items - 1];
            int excluded = _ZeroOneKnapsack(weight, profit, maxWt, items - 1);
            memo[items][maxWt] = Math.max(included, excluded);

            // Display the current max weight and the step details
            stepsArea.append("Considering item with profit " + profit[items - 1] + " and weight " + weight[items - 1] + " at remaining capacity " + maxWt + ":\n");
            stepsArea.append(" - Include item: New profit = " + included + "\n");
            // stepsArea.append(" - Exclude item: Profit remains = " + excluded + "\n\n");

        } else {
            memo[items][maxWt] = _ZeroOneKnapsack(weight, profit, maxWt, items - 1);
            stepsArea.append("Cannot include item with profit " + profit[items - 1] + " and weight " + weight[items - 1] + " at remaining capacity " + maxWt + ". Profit remains = " + memo[items][maxWt] + "\n\n");
        }

        return memo[items][maxWt];
    }

    private double _fractionalKnapsack(int[] weight, int[] profit, int maxWt, int items) {
        double[] profitWeightRatio = new double[items];
        for (int i = 0; i < items; ++i) {
            profitWeightRatio[i] = (double) profit[i] / weight[i]; // Calculate profit-to-weight ratio
        }

        // Bubble sort the items based on profit/weight ratio in descending order
        for (int i = 0; i < items - 1; ++i) {
            for (int j = 0; j < items - i - 1; ++j) {
                if (profitWeightRatio[j] < profitWeightRatio[j + 1]) {
                    // Swap corresponding weights
                    int tempWeight = weight[j];
                    weight[j] = weight[j + 1];
                    weight[j + 1] = tempWeight;

                    // Swap corresponding profits
                    int tempProfit = profit[j];
                    profit[j] = profit[j + 1];
                    profit[j + 1] = tempProfit;
                }
            }
        }

        double totalProfit = 0;
        for (int i = 0; i < items; ++i) {
            int currentWeight = weight[i];
            int currentProfit = profit[i];

            if (currentWeight <= maxWt) {
                totalProfit += currentProfit;
                maxWt -= currentWeight;
                stepsArea.append("Taking full item with profit " + currentProfit + " and weight " + currentWeight + ". New total profit: " + totalProfit + "\n");
            } else {
                double addedProfit = (double) currentProfit * ((double) maxWt / currentWeight);
                totalProfit += addedProfit;
                stepsArea.append("Taking part of item with profit " + currentProfit + " and weight " + currentWeight + ". Added profit: " + addedProfit + ". New total profit: " + totalProfit + "\n");
                break;
            }
        }

        return totalProfit;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            KnapsackGUI2 gui = new KnapsackGUI2();
            gui.setVisible(true);
        });
    }
}
