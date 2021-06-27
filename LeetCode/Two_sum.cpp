class Solution {
public:
    vector<int>out;
    vector<int> twoSum(vector<int>& nums, int target) {
        int size;
        size=nums.size();
        for(int j=0;j<size;j++){
            for(int i=j+1;i<size;i++){
                if(nums.at(i)==target-nums.at(j)){
                    out.push_back(j);
                    out.push_back(i);
                }
            }
        }
        return out;
    }
};
