#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    void combinations(vector<vector<int>> &ans, vector<int> Currcomb ,int Currsum, int Currindex, int target, vector<int> candidates){
        if(Currsum> target) return ;
        else if(Currsum == target){      
            ans.push_back(Currcomb);
            return ;
        }
        for(int i=Currindex; i<candidates.size(); i++){
            if(i> Currindex && candidates[i] == candidates[i - 1]) continue;
            Currsum += candidates[i];
            Currcomb.push_back(candidates[i]);
            combinations(ans, Currcomb, Currsum, i+1, target, candidates);
            Currsum -= candidates[i];
            Currcomb.pop_back();
        }
       
    }

    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> Currcomb;
        sort(candidates.begin(), candidates.end());     
        combinations(ans, Currcomb, 0,0,target, candidates);
        return ans ;
    }
};

