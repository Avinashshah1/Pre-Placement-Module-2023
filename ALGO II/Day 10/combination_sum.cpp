class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> con {};
		vector<vector<int>> sol1 {};
		for(int i = 0; i <= target; i ++) con.push_back(sol1);
		for(int k = 0; k <= target; k ++) {
			vector<vector<int>> sol {};
			set<vector<int>> se {};
			sort(candidates.begin(), candidates.end());
			if(k == 0) continue;
			else {
				for(int i = 0; i < candidates.size(); i++) {
					int n = k - candidates[i];
					if(n < 0) break;
					else if(n == 0) {
						vector<int> v {candidates[i]};
						se.insert(v);
					} else {
						vector<vector<int>> vt = con[n];
						for(int j = 0; j < vt.size(); j ++) {
							vt[j].push_back(candidates[i]);
							sort(vt[j].begin(), vt[j].end());
							se.insert(vt[j]);
						}
					}
				}
				for(auto it = se.begin(); it != se.end(); it ++) sol.push_back((*it));
				con[k] = sol;
			}
		}
		return con[target];
	}
};