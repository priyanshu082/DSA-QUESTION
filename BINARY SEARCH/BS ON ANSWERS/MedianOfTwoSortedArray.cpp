#include<iostream>

using namespace std;

//space complexity 1 solition but time complxity is still o(n)
double median(vector<int>& nums1, vector<int>& nums2) {
	     int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;

        int cnt=0;
        int ind2=n/2;
        int ind1=ind2-1;

        int indel2,indel1;
        int i=0,j=0;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) indel1=nums1[i];
                if(cnt==ind2) indel2=nums1[i];
                cnt++;
                i++;
            } else{
                if(cnt==ind1) indel1=nums2[j];
                if(cnt==ind2) indel2=nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
               if(cnt==ind1) indel1=nums1[i];
                if(cnt==ind2) indel2=nums1[i];
                cnt++;
                i++;
        }

        while(j<n2){
                 if(cnt==ind1) indel1=nums2[j];
                if(cnt==ind2) indel2=nums2[j];
                cnt++;
                j++;
        }

        if(n%2==1) return indel2;

        return (double)(indel1+indel2)/2.0;
}


//optimal appraoch for this solution


int main(){

    return 0;
}