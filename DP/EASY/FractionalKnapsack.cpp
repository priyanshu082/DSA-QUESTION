#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    int weight;
    int value;
    double ratio;

    Item(int w, int v) : weight(w), value(v)
    {
        ratio = (double)value / weight;
    }
};

class Knapsack
{

private:
    vector<Item> items;
    int capacity;

public:
    Knapsack(int cap) : capacity(cap) {};

    void addItem(int w, int v)
    {
        items.emplace_back(w, v);
    }

    static bool compareAndSortItems(const Item &a, const Item &b)
    {
        return a.ratio > b.ratio;
    }

    double getMaxProfit()
    {
        sort(items.begin(), items.end(), compareAndSortItems);

        double totalValue = 0;
        int remainingCapacity = capacity;

        for (size_t i = 0; i < items.size(); ++i)
        {
            const Item &item = items[i];

            if (item.weight <= remainingCapacity)
            {
                totalValue += item.value;
                remainingCapacity -= item.weight;
            }
            else
            {
                totalValue += item.ratio * remainingCapacity;
                break;
            }
        }
        return totalValue;
    }
};

int main()
{

    int n, weight, value, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    Knapsack Knapsack(capacity);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weight;
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> value;
        Knapsack.addItem(weight, value);
    }

    cout << "Maximum profit: " << Knapsack.getMaxProfit() << endl;

    return 0;
}