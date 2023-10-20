#include<iostream>
#include<vector>

using namespace std;

void MaxProfitFinder(vector<int>& prices,int i,int &maxProfit,int& minPrice){
    //base case
    if(i==prices.size()) return;


    minPrice=min(minPrice,prices[i]);
    int todayProfit=prices[i]-minPrice;
    maxProfit=max(maxProfit,todayProfit);

    
    MaxProfitFinder(prices,i+1,maxProfit,minPrice);
}

int main(){
    int n;
    cout<<"Enter the size of the price list"<<endl;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
        int maxProfit=INT_MIN;
        int minPrice=INT_MAX;
    MaxProfitFinder(prices,1,maxProfit,minPrice);
    cout<<"Hence the max Profit is : "<<maxProfit<<endl;
    return 0;
}