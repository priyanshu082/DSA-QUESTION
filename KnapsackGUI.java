import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Item {
    int weight;
    int value;

    Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }

    @Override
    public String toString() {
        return "Weight: " + weight + ", Value: " + value;
    }
}

class Knapsack {
    private int n;
    private int capacity;
    private ArrayList<Item> itemsArray;
    private int[][] dp;

    //constructor for knapsack
    Knapsack(int capacity, int n) {
        this.capacity = capacity;
        this.n = n;
        this.itemsArray = new ArrayList<>();
        this.dp = new int[n][capacity + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                dp[i][j] = -1;
            }
        }
    }

    void addItem(int weight, int value) {
        itemsArray.add(new Item(weight, value));
    }

    int Zero_One_Knapsack(int cap, int index, JTextArea stepsArea) {
        if (index < 0)
            return 0;
        if (dp[index][cap] != -1)
            return dp[index][cap];

        int select = Zero_One_Knapsack(cap, index - 1, stepsArea);
        int notSelect = Integer.MIN_VALUE;

        if (cap >= itemsArray.get(index).weight) {
            notSelect = itemsArray.get(index).value + Zero_One_Knapsack(cap - itemsArray.get(index).weight, index - 1, stepsArea);
        }

        dp[index][cap] = Math.max(select, notSelect);

        stepsArea.append("Considering item " + (index + 1) + ": Weight = " + itemsArray.get(index).weight + ", Value = "
                + itemsArray.get(index).value + "\n");
        stepsArea.append("Max Profit at capacity " + cap + " is " + dp[index][cap] + "\n\n");

        return dp[index][cap];
    }

    int profitCalculator(JTextArea stepsArea) {
        if (n == 1) {
            if (capacity >= itemsArray.get(0).weight) {
                return itemsArray.get(0).value;
            } else {
                return 0;
            }
        }
        return Zero_One_Knapsack(capacity, n - 1, stepsArea);
    }

    double fractionalKnapsack(JTextArea stepsArea) {
        Collections.sort(itemsArray, new Comparator<Item>() {
            @Override
            public int compare(Item item1, Item item2) {
                double ratio1 = (double) item1.value / item1.weight;
                double ratio2 = (double) item2.value / item2.weight;
                return Double.compare(ratio2, ratio1);
            }
        });

        double totalValue = 0.0;
        int currentWeight = 0;

        stepsArea.append("Fractional Knapsack Steps:\n");

        for (Item item : itemsArray) {
            if (currentWeight + item.weight <= capacity) {
                currentWeight += item.weight;
                totalValue += item.value;
                stepsArea.append("Added item: Weight = " + item.weight + ", Value = " + item.value + " (100%)\n");
            } else {
                int remainingCapacity = capacity - currentWeight;
                double fraction = (double) remainingCapacity / item.weight;
                totalValue += item.value * fraction;
                stepsArea.append("Added item: Weight = " + item.weight + ", Value = " + item.value + 
                                 " (" + String.format("%.2f", fraction * 100) + "%)\n");
                break;
            }
        }

        stepsArea.append("Total value: " + String.format("%.2f", totalValue) + "\n");
        return totalValue;
    }

    ArrayList<Item> getItems() {
        return itemsArray;
    }
}

public class KnapsackGUI {
    private JFrame frame;
    private JTextField nInput;
    private JTextField capacityInput;
    private JTextField weightInput;
    private JTextField valueInput;
    private JScrollPane itemsScrollPane;
    private JScrollPane stepsScrollPane;
    private Knapsack knapsack;
    private int itemCount = 0;

    public static void main(String[] args) {
        SwingUtilities.invokeLater(KnapsackGUI::new);
    }

    public KnapsackGUI() {
        frame = new JFrame("Knapsack Problem");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 800);
        frame.setLayout(null);

        JLabel nLabel = new JLabel("Number of Items:");
        nLabel.setBounds(10, 10, 150, 25);
        frame.add(nLabel);

        nInput = new JTextField();
        nInput.setBounds(160, 10, 200, 25);
        frame.add(nInput);

        JLabel capacityLabel = new JLabel("Knapsack Capacity:");
        capacityLabel.setBounds(10, 40, 150, 25);
        frame.add(capacityLabel);

        capacityInput = new JTextField();
        capacityInput.setBounds(160, 40, 200, 25);
        frame.add(capacityInput);

        JLabel weightLabel = new JLabel("Weight:");
        weightLabel.setBounds(10, 70, 150, 25);
        frame.add(weightLabel);

        weightInput = new JTextField();
        weightInput.setBounds(160, 70, 200, 25);
        frame.add(weightInput);

        JLabel valueLabel = new JLabel("Value:");
        valueLabel.setBounds(10, 100, 150, 25);
        frame.add(valueLabel);

        valueInput = new JTextField();
        valueInput.setBounds(160, 100, 200, 25);
        frame.add(valueInput);

        JButton addButton = new JButton("Add Item");
        addButton.setBounds(10, 130, 100, 25);
        frame.add(addButton);
        

        JButton deleteButton = new JButton("Delete All");
        deleteButton.setBounds(130, 130, 100, 25);
        frame.add(deleteButton);

        JButton calculateButton = new JButton(" 0-1 KnapSack");
        calculateButton.setBounds(250, 130, 150, 25);
        frame.add(calculateButton);

        JButton fractionalButton = new JButton("Fractional Knapsack");
        fractionalButton.setBounds(450, 130, 150, 25);
        frame.add(fractionalButton);

        JTextArea itemsArea = new JTextArea();
        itemsArea.setEditable(false);
        itemsScrollPane = new JScrollPane(itemsArea);
        itemsScrollPane.setBounds(10, 160, 350, 100);
        frame.add(itemsScrollPane);

        JTextArea stepsArea = new JTextArea();
        stepsArea.setEditable(false);
        stepsScrollPane = new JScrollPane(stepsArea);
        stepsScrollPane.setBounds(10, 270, 750, 450);
        frame.add(stepsScrollPane);

        
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nText = nInput.getText();
                if (nText.isBlank() || Integer.parseInt(nText) <= 0) {
                    JOptionPane.showMessageDialog(frame, "Please set the number of items (n) to a value greater than 0.", "Input Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }
        
                if (knapsack == null) {
                    int n = Integer.parseInt(nInput.getText());
                    int capacity = Integer.parseInt(capacityInput.getText());
                    knapsack = new Knapsack(capacity, n);
                }
        
                int weight = Integer.parseInt(weightInput.getText());
                int value = Integer.parseInt(valueInput.getText());
                knapsack.addItem(weight, value);
                itemCount++;
        
                // Reset fields
                weightInput.setText("");
                valueInput.setText("");
        
                // Display the items added so far
                itemsArea.append("Item " + itemCount + ": Weight = " + weight + ", Value = " + value + "\n");
        
                if (itemCount == Integer.parseInt(nInput.getText())) {
                    addButton.setEnabled(false);
                }
            }
        });
        

        
        
        deleteButton.addActionListener(new ActionListener () {
            @Override 
            public void actionPerformed(ActionEvent e){
                nInput.setText("");
                capacityInput.setText("");
                weightInput.setText("");
                valueInput.setText("");
                itemsArea.setText("");
                stepsArea.setText("");
                knapsack = null;
                itemCount = 0;
                addButton.setEnabled(true);
            }

            
        });

        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (knapsack != null) {
                    stepsArea.setText(""); // Clear previous steps
                    stepsArea.append("0-1 Knapsack Steps:\n");
                    int maxProfit = knapsack.profitCalculator(stepsArea);
                    stepsArea.append("Maximum Profit: " + maxProfit + "\n");
                }
            }
        });

        fractionalButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (knapsack != null) {
                    stepsArea.setText(""); // Clear previous steps
                    double maxProfit = knapsack.fractionalKnapsack(stepsArea);
                    stepsArea.append("Maximum Profit (Fractional): " + String.format("%.2f", maxProfit) + "\n");
                }
            }
        });

        frame.setVisible(true);
    }
}