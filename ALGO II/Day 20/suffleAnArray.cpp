class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        this->nums = nums;
    }
    
    vector<int> reset() {
        return this->nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuf(this->nums);
        int n = shuf.size();
        
        for(int i = 0; i < n; i++){
            // get random index to swap with nums[i]
            int ran = rand() % n;
            swap(shuf[i], shuf[ran]);
        }
        return shuf;
    }
};