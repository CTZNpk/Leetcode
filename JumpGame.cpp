#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int recur(vector<int> &nums, int pos){
        int check = pos+nums[pos];
        int index =nums[pos] ;
        if(check >= nums.size() -1)
            return index ;

        for(int i=pos+1; i<=pos+nums[pos] ; i++){
            if(i+ nums[i] > check){
                index = i - pos ;
                check = i+nums[i];
            }
        }
        return index ;

    }


public:
    int jump(vector<int> &nums)
    {
        int jump= 0;
        int highest = 0;
        for (int i = 0; i < nums.size() -1; i+= highest, jump++)
        {
            highest = recur(nums, i) ;
            
        }   
        return jump ;
    }
};

int main()
{
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    cout << Solution::jump(nums);

    return 0;
}