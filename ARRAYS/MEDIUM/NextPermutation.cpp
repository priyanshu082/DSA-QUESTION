#include <iostream>

using namespace std;


//one way is to sort all the possible permuatation and than do a linear search in that vector

//other way is to use next_permutation stl which is in built in c++
//and writting the code of that STL.
        void revArr( vector<int>& nums,int start,int end){
          while(start<end){
              int temp=nums[start];
              nums[start]=nums[end];
              nums[end]=temp;
              start++;
              end--;
          }
        }

    void nextPermutation(vector<int>& nums) {

        int n=nums.size();
        int index=-1;
        if(n==1){

        } else {
     for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
               index=i;
               break;
            }
        }

        if(index==-1){
            revArr(nums,0,n-1);
        }
        if(index!=-1){
            for(int i=n-1;i>index;i--){
             if(nums[index]<nums[i]){
                 swap(nums[index],nums[i]);
                 break;
             }
        }
        revArr(nums,index+1,n-1);
        }
        
        }
       
    }




int main(){
     
    return 0;
}