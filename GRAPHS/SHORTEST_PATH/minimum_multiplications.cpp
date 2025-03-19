//{ Driver Code Starts
// Initial Template for C++

#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        queue<pair<int,int>> q;
        vector<int> dist(mod,1e9);
        if(start==end) return 0;
        q.push({0,start});
        dist[start]=0;
        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto it : arr){
                int newNode=(node*it) % mod;
                // int newDis=dis+dist[newNode];
                if(newNode==end) return dis+1;
                if(  dis + 1 < dist[newNode] ){
                    dist[newNode]=dis+1;
                    q.push({dis+1 , newNode});
                }
                
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends