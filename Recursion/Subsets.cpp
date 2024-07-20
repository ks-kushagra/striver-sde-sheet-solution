Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  class Solution {
public:
/**

1 2 3
[]
    [1]
[1,2]   [2]

*/
vector<vector<int>> ans;

    void solve(vector<int> nums , int n , vector<int> t, int index){
        if (index > n){
            return;
        }
        ans.push_back(t);
        for (int i=index;i<n;i++){
            t.push_back(nums[i]);
            solve(nums,n,t,i+1);
            t.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums,n,temp,0);
        return ans;
    }
};


