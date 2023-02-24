#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
    static void recurFunc(vector<int>&nums, vector<vector<int>>& tempans, vector<int> temp, vector<bool>& check){
        if(temp.size() == nums.size()){
            tempans.push_back(temp);
            return ;
            
        }
        unordered_set<int> s ;
        for(int i=0; i<nums.size(); i++){
           if(s.find(nums[i]) != s.end()) continue;
           if(check[i]) continue;
           s.insert(nums[i]);
            temp.push_back(nums[i]);
             check[i] = true ;
            recurFunc(nums, tempans,temp, check);
            temp.pop_back();
            check[i] = false ;
        }
    }


public:
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> tempans;
        vector<int> temp ;
        vector<bool> check(nums.size(),false) ;
        recurFunc(nums, tempans, temp, check);
        return tempans ;
    }
};
int main (){
    vector<int> nums = {1,1,3};
    vector<vector<int>> ans = Solution::permuteUnique(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << "\t";
        }
        cout << endl ;
    }

return 0 ;
}