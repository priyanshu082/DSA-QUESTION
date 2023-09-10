#include<iostream>

using namespace std;

int findMinDifference(vector<string>& timePoints) {
        //step 1 convert all the string into minutes of integer
        vector<int> minute;
        int n=timePoints.size();
       for(int i=0;i<n;i++){
           string curr=timePoints[i];
           int hours=stoi(curr.substr(0,2));
           int min=stoi(curr.substr(3,2));
           int totalMin=hours*60+min;
           minute.push_back(totalMin);
       }

       //sort the minute
       sort(minute.begin(),minute.end());
       //finding the minimum diffrece
       int mini=INT_MAX;
       for(int i=0;i<minute.size()-1;i++){
           int diff=minute[i+1]-minute[i];
        //    if(diff>720) {
        //        diff=1440-diff;
        //    } 
           mini=min(diff,mini);
       }

       int lastDiff=(minute[0]+1440)-minute[minute.size()-1];
        mini=min(lastDiff,mini);
       return mini;
    }


int main(){

    return 0;
}