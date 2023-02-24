#include<iostream>
#include<vector>
using namespace std;
class Solution {
    static void recurFunc(vector<int>&nums, vector<vector<int>>& tempans, vector<int> temp, vector<bool>& check){
        if(temp.size() == nums.size()){
            tempans.push_back(temp);
            return ;
        }
        for(int i=0; i<nums.size(); i++){
           if(check[i]) continue;
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
        for(int i=0; i< nums.size();i++){
            check[i] = true ;
            temp.push_back(nums[i]);
            recurFunc(nums, tempans, temp, check);
            temp.pop_back();
            check[i] = false ;
        }
        return tempans ;
    }
};
int main (){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = Solution::permute(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << "\t";
        }
        cout << endl ;
    }

return 0 ;
}