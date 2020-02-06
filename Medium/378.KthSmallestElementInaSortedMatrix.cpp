class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
                priority_queue<int> pq;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();
        while(left<right)
        {
            int mid = left+(right-left)/2, cnt=0;
            for(int i=0;i<matrix.size();i++)
            {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }                      
            if(cnt<k)
                left = mid +1;
            else 
                right = mid;
        }
        return left;
    }
};