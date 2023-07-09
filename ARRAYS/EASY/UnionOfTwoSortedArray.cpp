#include <iostream>
#include <set>
#include <vector>

using namespace std;

// brute approach for solving the question
 int Union(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    int i = 0;
    int comb[s.size()];
    for (auto it : s)
    {
        comb[i] = it;
        i++;
    }
    return comb[s.size()];
}

//optimal appraoch for solving the question
vector<int> Union2(int arr1[],int arr2[],int n,int m){
   vector<int> UnionArr;
   int i=0,j=0;
   while(i<n && j<m){
    if(arr1[i]<=arr2[j]){
        if(UnionArr.size()==0||UnionArr.back()!=arr1[i]){
            UnionArr.push_back(arr1[i]);
        }
        i++;
    } else{
      if(UnionArr.size()==0 || UnionArr.back()!=arr2[j]){
            UnionArr.push_back(arr2[j]);
        }
    j++;
    }
   }

   while(i<n){
        if(UnionArr.size()==0||UnionArr.back()!=arr1[i]){
            UnionArr.push_back(arr1[i]);
        }
        i++;
   }

   while(j<m){
      if(UnionArr.size()==0 || UnionArr.back()!=arr2[j]){
            UnionArr.push_back(arr2[j]);
        }
    j++;
   }

   return UnionArr;

}

//intersection of two arrays
vector<int> Intersection(int arr1[],int arr2[],int n,int m ){
      vector<int> Inter;
      int i=0;
      int j=0; 
      
      while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            Inter.push_back(arr1[i]);
            i++;
            j++;
        }
      }

      return Inter;

}

int main()
{
    
   int n,m;
   cout<<"The first array"<<endl;
   cin>>n;
   int arr1[n];
   for(int i=0;i<n;i++){
    cin>> arr1[i];
   }

   cout<<"The Second array"<<endl;
   cin>>m;
   int arr2[m];
   for(int i=0;i<m;i++){
    cin>> arr2[i];
   }

   for(int i=0;i<n;i++){
      cout<<arr1[i]<<" ";
   }
   cout<<endl;

   for(int i=0;i<m;i++){
      cout<<arr2[i]<<" ";
   }
   cout<<endl;

  vector<int> intersection=Intersection(arr1,arr2,n,m);

  for(size_t i=0;i<intersection.size();i++){
    cout<< intersection[i] << " ";
  }
  cout<<endl;

    return 0;
}