class Solution {
public:

    void build(int node,int start,int end,vector<pair<long long,int>>&seg,vector<long long>&p,vector<int>&nums)
    {
        if(start==end)
        {
            seg[node]={p[start]-nums[start],start};
            return;
        }

        int mid=(start+end)/2;

        build(2*node,start,mid,seg,p,nums);
        build(2*node+1,mid+1,end,seg,p,nums);

        if(seg[2*node].first<=seg[2*node+1].first)
            seg[node]=seg[2*node];
        else
            seg[node]=seg[2*node+1];
    }

    pair<long long,int> query(int node,int start,int end,int l,int r,vector<pair<long long,int>>&seg)
    {
        if(r<start || end<l)
            return {LLONG_MAX,-1};

        if(l<=start && end<=r)
            return seg[node];

        int mid=(start+end)/2;

        pair<long long,int> p=query(2*node,start,mid,l,r,seg);
        pair<long long,int> q=query(2*node+1,mid+1,end,l,r,seg);

        if(p.first<=q.first)
            return p;
        else
            return q;
    }

    int shortestSubarray(vector<int>& nums, int k)
    {
        int n=nums.size();

        vector<long long>p(n);

        for(int i=0;i<n;i++)
        {
            if(i==0)
                p[i]=nums[i];
            else
                p[i]=p[i-1]+nums[i];
        }

        vector<pair<long long,int>>seg(4*n);

        build(1,0,n-1,seg,p,nums);

        int le=n+1;

        for(int i=0;i<n;i++)
        {
            int l=0,r=i,ans=-1;

            while(l<=r)
            {
                int mid=(l+r)/2;

                pair<long long,int> q=query(1,0,n-1,mid,i,seg);

                if(p[i]-q.first>=k)
                {
                    ans=q.second;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }

            if(ans!=-1)
                le=min(le,i-ans+1);
        }

        if(le==n+1)
            return -1;

        return le;
    }
};