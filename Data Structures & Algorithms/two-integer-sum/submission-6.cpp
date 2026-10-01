class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;

        for (int i=0;i<nums.size();i++){
            int comple = target - nums[i];
            if (seen.find(comple)!=seen.end()){
                return {seen[comple],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};
