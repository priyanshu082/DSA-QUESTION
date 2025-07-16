#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<int>> monsters;
vector<vector<char>> visited;
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
string dir = "URDL";

bool isValid(int newrow, int newcol, int t)
{
    return newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && visited[newrow][newcol] == '_' && grid[newrow][newcol] != '#' && monsters[newrow][newcol] > t + 1;
}

vector<char> buildPath(pair<int, int> start, pair<int, int> end)
{
    vector<char> path;
    int row = end.first;
    int col = end.second;
    while (make_pair(row, col) != start)
    {
        char c = visited[row][col];
        path.push_back(c);
        if (c == 'D')
            row--;
        else if (c == 'U')
            row++;
        else if (c == 'L')
            col++;
        else if (c == 'R')
            col--;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    monsters.assign(n, vector<int>(m, INT_MAX));
    visited.assign(n, vector<char>(m, '_'));

    vector<pair<int, int>> mons;
    pair<int, int> start;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'M')
                mons.push_back({i, j});
        }
    }

    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < mons.size(); i++)
    {
        int row = mons[i].first;
        int col = mons[i].second;
        q.push({0, {row, col}});
        monsters[row][col] = 0;
    }

    while (!q.empty())
    {
        int row = q.front().second.first;
        int col = q.front().second.second;
        int t = q.front().first;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int newrow = row + drow[k];
            int newcol = col + dcol[k];
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] != '#' && monsters[newrow][newcol] > t + 1)
            {
                monsters[newrow][newcol] = t + 1;
                q.push({t + 1, {newrow, newcol}});
            }
        }
    }

    if (monsters[start.first][start.second] <= 0) {
        cout << "NO" << endl;
        return 0;
    }

    q.push({0, start});
    visited[start.first][start.second] = 'S';
    pair<int, int> end = {-1, -1};
    while (!q.empty())
    {
        int row = q.front().second.first;
        int col = q.front().second.second;
        int t = q.front().first;
        q.pop();
        if ( monsters[row][col] <= t)
            continue;
        if ((row == 0 || col == 0 || row == n - 1 || col == m - 1) && grid[row][col] != '#')
        {
            end = {row, col};
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int newrow = row + drow[i];
            int newcol = col + dcol[i];
            char c = dir[i];
            if (isValid(newrow, newcol, t))
            {
                visited[newrow][newcol] = c;
                q.push({t + 1, {newrow, newcol}});
            }
        }
    }

    if (end.first != -1 && end.second != -1)
    {
        vector<char> path = buildPath(start, end);
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (auto ch : path)
        {
            cout << ch;
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}