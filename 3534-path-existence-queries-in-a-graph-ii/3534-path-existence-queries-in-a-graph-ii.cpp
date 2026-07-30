class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                           vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for(int i=0;i<n;i++)
            pos[a[i].second]=i;

        // Connected components
        vector<int> comp(n);
        comp[0]=0;
        for(int i=1;i<n;i++){
            comp[i]=comp[i-1];
            if(a[i].first-a[i-1].first>maxDiff)
                comp[i]++;
        }

        // Next jump
        vector<int> nxt(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n && a[j+1].first-a[i].first<=maxDiff)
                j++;
            nxt[i]=j;
        }

        int LOG=20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i=0;i<n;i++)
            up[0][i]=nxt[i];

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q:queries){
            int l=pos[q[0]];
            int r=pos[q[1]];

            if(l>r) swap(l,r);

            if(comp[l]!=comp[r]){
                ans.push_back(-1);
                continue;
            }

            int steps=0;
            int cur=l;

            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur]<r){
                    cur=up[k][cur];
                    steps+=(1<<k);
                }
            }

            if(cur<r) steps++;

            ans.push_back(steps);
        }

        return ans;
    }
};