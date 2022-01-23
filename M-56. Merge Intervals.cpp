M-56. Merge Intervals

class Solution {
public:
    static bool comparator( vector<int>& a, vector<int>& b )
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort( intervals.begin(), intervals.end(), comparator );
        int low=intervals[0][0];
        int high=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> v;
            if(intervals[i][0]>high)
            {
                v.push_back(low);
                v.push_back(high);
                ans.push_back(v);
                low=intervals[i][0];
                high=intervals[i][1];
            }
            else
            {
                if(intervals[i][1]>high)
                {
                    high=intervals[i][1]; 
                }
            }
        }
        vector<int> v;
        v.push_back(low);
        v.push_back(high);
        ans.push_back(v);
        return ans;
    }
};