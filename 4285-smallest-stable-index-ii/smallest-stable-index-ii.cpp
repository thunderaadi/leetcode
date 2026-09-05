class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        

        vector<int>mi((int)nums.size()),ma((int)nums.size());

        for(int i=0;i<(int)nums.size();i++)
        {
             if(i==0)ma[i]=nums[i];
             else
            {
                ma[i]=max(ma[i-1],nums[i]);
            }
        }
         int  ans = INT_MAX;
         int count =0;
        for(int i=(int)nums.size()-1;i>=0;i--)
        {

             if(i==(int)nums.size()-1)mi[i]=nums[i];
             else
            {
                mi[i]=min(mi[i+1],nums[i]);
            }
             if((ma[i]-mi[i])<=k)
             {
               ans=min(ans,i);
               count++;
             }

        }
        if(count>0)
        return ans;
        else return -1;


    }
};