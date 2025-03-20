//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    
    int powerof2(int n){
       
    }
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int ans=0;
       while(n>0){
            int x=0;
            while((1 << x)<=n) x++;
            x--;
            
            ans+=(1 << (x-1))* x;
            
            ans+=(n- (1 << x) +1);
            
            n-=(1 << x);
       }
       
       return ans;
       
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends