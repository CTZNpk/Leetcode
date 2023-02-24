#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<3; i++){
            for(int j=0 ;j< n/2; j++){
                for(int k=0; k<n/2 + n%2; k++){
                    if(i==0)
                    swap(matrix[j][k], matrix[k][n-j-1]);
                    if(i==1)
                    swap(matrix[j][k], matrix[n-j-1][n-k-1]);
                    if(i==2)
                    swap(matrix[j][k], matrix[n-k-1][j]);
                }
            }
        }
    }
};
int main (){
    vector<vector<int>> matrix  =  {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution::rotate(matrix);
    for(int i=0; i<matrix.size();i++){
        for(int j=0; j< matrix[i].size(); j++){
            cout << matrix[i][j]<< "\t";
        }
        cout << endl ;
    }

return 0 ;
}
/*BEST SOLUTION 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int rows=matrix.size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<rows;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }


    }
};*/