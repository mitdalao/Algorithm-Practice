/*
题目描述：
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/
/*
算法：
hash思想，线性扫描过程中计数
时间复杂度O(n)
空间复杂度O(n)
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        int hash[nums.size()];
        memset(hash, 0, nums.size() * 4);
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
            if(hash[nums[i]] > 1){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};