#include<iostream>
#include<vector>

using namespace std;

class Items{
    public:
    int weight;
    int value; 

    Items(int w,int v): weight(w),value(v){};

};

class Knapsack{
    private:
    int n;
    int capacity;
    vector<Items> items;
    vector<vector<int>> dp;
    public:
    Knapsack(int c, int n): capacity(c),n(n){
         dp = vector<vector<int>>(n, vector<int>(capacity + 1, -1));
    };

    void addItem(int w,int v){
        items.emplace_back(w,v);
    }

    int getMaxProfit(int cap, int index){
        if(index<0) return 0;
        if(dp[index][cap]!=-1) return dp[index][cap];
      int select=0+getMaxProfit(cap,index-1);
      int notSelect=INT16_MIN;
      if(cap>items[index].weight){
        notSelect=items[index].value+getMaxProfit(cap-items[index].weight,index-1);
      }
      dp[index][cap]=max(select,notSelect);
      return max(select,notSelect);
    }

    int profitCalculator(){
        if(n==1){
            if(capacity>=items[0].weight){
                return items[0].value;
            }else{
                return 0;
            }
        }
        return getMaxProfit(capacity,n-1);
    }

};

int main(){

     int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    Knapsack Knapsack(capacity,n);

    for (int i = 0; i < n; i++)
    {
        int weight ,value;
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weight;
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> value;
        Knapsack.addItem(weight, value);
    }

    cout << "Maximum profit: " << Knapsack.profitCalculator() << endl;

    return 0;
}