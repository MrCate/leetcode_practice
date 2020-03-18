class Solution {
public:
    static bool cmp(pair<char ,int> a, pair<char ,int> b){
        return a.second<b.second;       
    }
    string minWindow(string s, string t) {
        vector<pair<char,int>> c;
        for(int i = 0;i<t.length();i++){
            int position = 0;
            while((position=s.find(t[i],position))!=string::npos){
                    c.push_back({t[i], position});
                    position++;
                }   
        }
        sort(c.begin(),c.end(),cmp);
        vector<pair<char,int>> ans;
        int p;
        int n = INT_MAX;
        for(int i=0;i<c.size()-t.size()+1;i++){
            for(int j=i;j<i+t.size();j++){
                ans.push_back({c[j].first,c[j].second});
            }
            if(isEndependence(ans) == true){
                if(ans[i+t.size()-1].second-ans[i].second+1<n){
                    n=ans[i+t.size()-1].second-ans[i].second+1;
                    p = i;
                }
            }
            ans.clear();
        }
        return s.substr(p,n);
    }
    bool isEndependence(vector<pair<char,int>>& nums){
        if(nums.empty())
            return false;
        for(int i =0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    return false;
            }
        }
        return true;
    }

};