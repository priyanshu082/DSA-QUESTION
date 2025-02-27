 #include<iostream>
 #include<vector>
 #include<queue>
 using namespace std;
 
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        int initial=image[sr][sc];
        q.push({sr,sc});
        image[sr][sc]=color;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if( nrow < image.size() && nrow>=0 && ncol <image[0].size() && ncol>=0 && !vis[nrow][ncol] && image[nrow][ncol]==initial && image[nrow][ncol]!=color){
                    image[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            
        }
        return image;
 }

 int main(){
    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1,color=2;
    vector<vector<int>> ans=floodFill(image,sr,sc,color);
    for(int i=0;i<ans.size();i++){
        
 }