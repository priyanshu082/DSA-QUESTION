#include<iostream>
using namespace std; 

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e8));

        for(auto it : edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++) mat[i][i]=0;

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j], mat[i][via]+mat[via][j]);
                }
            }
        }

        int city=-1;
        int minCity=n;
        for(int i=0;i<n;i++){
            int tempMinCity=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold) tempMinCity++;
            }

            if(minCity>=tempMinCity){
                minCity=tempMinCity;
                city=i;
            }
        }

        return city;
    }
};

int main(){
    return 0;
}