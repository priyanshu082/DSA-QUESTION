#include <iostream>
using namespace std;

//brute force solution
   int maxArea(vector<int>& height){
        int n=height.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int area=0;
            for(int j=i+1;j<n;j++){
                int len=j-i;
                area=min(height[j],height[i])*len;
            maxi=max(maxi,area);
            }
        }
        return maxi;
    }

//optimal solution
    int maxArea(vector<int>& height) {
        int area=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int h=min(height[left],height[right]);
            area=max(area,(right-left)*h);
            while(height[left]<=h && left<right) left++;
            while(height[right]<=h && left<right) right--;
        }
        return area;
    }

int main(){

    return 0;
}