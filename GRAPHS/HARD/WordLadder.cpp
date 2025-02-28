#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
           
            for(int i=0;i<=word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        if(word==endWord) return steps+1;
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

int main(){
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    string start="hit";
    string end="cog";
    Solution obj;
    cout<<obj.ladderLength(start,end,wordList);
    return 0;
}   