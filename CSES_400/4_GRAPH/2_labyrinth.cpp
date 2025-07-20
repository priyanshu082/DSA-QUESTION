#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<pair<int, int>>> parent;
vector<vector<bool>> visited;
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, -1, 0, 1};
string dir = "ULDR";
bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j];
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
}

string construct(pair<int, int> end, pair<int, int> start)
{
    string path="";
    pair<int,int> curr=end;
    while(curr!=start){
        pair<int, int> p = parent[curr.first][curr.second];
        for(int k=0;k<4;k++){
            if(curr.first-drow[k]==p.first && curr.second-dcol[k]==p.second){
                path+=dir[k];
                break;
            }
        }
        curr=p;
    }
    reverse(path.begin(),path.end());
    return path;
}
int main()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    parent.assign(n, vector<pair<int, int>>(m));
    visited.assign(n, vector<bool>(m, false));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (grid[i][j] == 'B')
            break;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + drow[k];
            int nj = j + dcol[k];
            if (isValid(ni, nj))
            {
                visited[ni][nj] = true;
                parent[ni][nj] = {i, j};
                q.push({ni, nj});
            }
        }
    }

    if (visited[end.first][end.second])
    {
        string path = construct(end, start);
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}