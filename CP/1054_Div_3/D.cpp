#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int r(vector<int> &pos)
{
    int n = pos.size();
    if (n <= 1)
        return 0;
    int mid = n / 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(pos[i] - (pos[mid] - mid + i));
    }
    return ans;
}

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         vector<int> pos_a,pos_b;
//         for(int i=0;i<n;i++){
//             if(s[i]=='a') pos_a.push_back(i);
//             else pos_b.push_back(i);
//         }

//         int ans=min(r(pos_a),r(pos_b));
//         cout<<ans<<endl;

//     }

// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> pra(n,0),prb(n,0),cnt(n,0);
        cnt[0] = s[0]=='a';
        for(int i=1;i<n;i++){
            pra[i]=pra[i-1];
            prb[i]=prb[i-1];
            cnt[i]=cnt[i-1];
            if(s[i]=='a'){
                cnt[i]++;
                prb[i]+=(i+1-cnt[i]);
            }else{
                pra[i]+=cnt[i];
            }
        }

        vector<int> sufa(n,0),sufb(n,0),scnt(n,0);
        scnt[n-1] = s[n-1]=='a';
        sufa[n-1]=0;
        sufb[n-1]=0;
        for(int i=n-2;i>=0;i--){
            sufa[i]=sufa[i+1];
            sufb[i]=sufb[i+1];
            scnt[i]=scnt[i+1];
            if(s[i]=='a'){
                scnt[i]++;
                sufb[i]+=(n-i-scnt[i]);
            }else{
                sufa[i]+=scnt[i];
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min({ans,pra[i]+sufa[i], prb[i]+sufb[i]});
        }
        cout<<ans<<endl;
    }
}
