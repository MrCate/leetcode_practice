class Solution {
public:
    static bool sort_rule(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(), sort_rule);
        int empty = 0;
        int cur = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(!pq.empty()){
                if(pq.top()>start)
                    break;
                pq.pop();
                empty++;
                cur--;
            }
            cur++;
            if(empty>0)
                empty--;
            else
                if(cur>res)
                    res=cur;
            pq.push(end);
        }
        return res;
    }
};