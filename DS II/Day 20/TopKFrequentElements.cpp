class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>  mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        priority_queue<pair<int,int>> pq;
        for(auto a=mp.begin();a!=mp.end();a++){
            pq.push({a->second,a->first});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};