Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>s;
    void solve(vector<int> nums , int n,vector<int> t, int index){
        if (index > n){
            return;
        }
        s.insert(t);
        for (int i=index;i<n;i++){
            t.push_back(nums[i]);
            solve(nums,n,t,i+1);
            t.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(nums, n,t,0);
        for(auto it = s.begin();it != s.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
