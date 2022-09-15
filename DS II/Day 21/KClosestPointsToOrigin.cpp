class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<k;i++){
            cout<<sqrt(pow(points[i][0],2)+pow(points[i][1],2))<<endl;
            pq.push({sqrt(pow(points[i][0],2)+pow(points[i][1],2)),i});
        }
        for(int i=k;i<points.size();i++){
            cout<<sqrt(pow(points[i][0],2)+pow(points[i][1],2))<<endl;
            if(sqrt(pow(points[i][0],2)+pow(points[i][1],2))<pq.top().first){
                pq.pop();
                pq.push({sqrt(pow(points[i][0],2)+pow(points[i][1],2)),i});
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};