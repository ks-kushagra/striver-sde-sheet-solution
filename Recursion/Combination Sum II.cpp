Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>s;
    void solve(vector<int> nums, int target, int n , int index, vector<int> t){
        if(index > n){
            return;
        }
        if(target ==0){
            s.insert(t);
            return;
        }
        for (int i =index;i<n;i++){
            if (i > index && nums[i] == nums[i-1]){
                continue;
            }
            if (nums[i] > target) break;
            if (target >= nums[i]){
                t.push_back(nums[i]);
                solve(nums,target-nums[i],n,i+1,t);
                t.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        int n = candidates.size();
        solve(candidates, target, n, 0,t);
        for(auto it=s.begin();it !=s.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
