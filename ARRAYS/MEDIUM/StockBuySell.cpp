#include<iostream>

using namespace std;

//o(n)
 int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
           int cost=prices[i]-mini;
           profit=max(profit,cost);
           mini=min(prices[i],mini);
        }
        return profit;
    }

int main (){
    
    return 0;
}