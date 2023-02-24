#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
   static vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans ;
    unordered_map<string , vector<string>> temp ;

    for(int i=0; i< strs.size(); i++){
        string s = strs[i];
        sort(strs[i].begin(), strs[i].end());
        temp[strs[i]].push_back(s);
    }
    
    for(auto i : temp)
        {
            ans.push_back(i.second);
        }
    return ans ;
}
};
int main (){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = Solution::groupAnagrams(strs);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << "\t";
        }
        cout << endl ;
    } 

    return 0 ;
}