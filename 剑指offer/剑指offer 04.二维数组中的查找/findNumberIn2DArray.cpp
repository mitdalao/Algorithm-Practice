/*
题目描述：
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
/*
算法：
若是方阵，从对角线出发，找到i，使得matrix[i-1][i-1](i可能是0) < target < matrix[i][i]
只需对matrix[0-i-1][i](列) 和matrix[i][0-i-1](行)分别进行二分查找即可
时间复杂度O(n + log n)

若非方阵，从右上角开始遍历，若matrix[i][j] > target, j--;matrix[i][j] < target, i++;
时间复杂度O(m + n)
*/

//方阵写法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            if(matrix[i][i] == target)
                return true;
            else if(matrix[i][i] > target){
                int first = 0, last = i - 1;
                int mid;
                while(first <= last){
                    mid = (first + last) / 2;
                    if(matrix[i][mid] > target){
                        last = mid - 1;
                    }
                    else if(matrix[i][mid] < target){
                        first = mid + 1;
                    }
                    else{
                        return true;
                    }
                }
                first = 0, last = i - 1;
                while(first <= last){
                    mid = (first + last) / 2;
                    if(matrix[mid][i] > target){
                        last = mid - 1;
                    }
                    else if(matrix[mid][i] < target){
                        first = mid + 1;
                    }
                    else{
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }
};

//非方阵写法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else
                return true;
        }
        return false;
    }
};