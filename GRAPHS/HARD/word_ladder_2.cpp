#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<string> vec;
        vec.push_back(beginWord);
        q.push(vec);
        // st.erase(beginWord);
        while(!q.empty()){
            vector<string> wordToRemove;
            int level=q.size();
                for(int j=0;j<level;j++){
                    vector<string> vec_q=q.front();
                    q.pop();
                    string word=vec_q.back();
                    for(int i=0;i<word.size();i++){
                        char original= word[i];
                        for(char ch='a';ch<='z';ch++){
                            word[i]=ch;
                            if(st.find(word)!= st.end()){
                                wordToRemove.push_back(word);
                                vector<string> temp=vec_q;
                                temp.push_back(word);
                                if(word==endWord) ans.push_back(temp);
                                else q.push(temp);
                            }
                        }
                    word[i]=original;
                    }
                }
                for(int p=0;p<wordToRemove.size();p++) st.erase(wordToRemove[p]);
            }
        return ans;
        }

    };

int main(){
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    string start="hit";
    string end="cog";
    unordered_set<string> st(wordList.begin(),wordList.end());
    Solution obj;
    vector<vector<string>> ans=obj.findLadders(start,end,wordList);
    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
    }
}