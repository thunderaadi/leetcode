class Solution {
public:
  int foo(vector<int>&v )
  {
    int n=v.size();
    int ans=0;
         for(int i=0;i<n;i++)
         {
            int c=1;
            bool done =false;
            for(int j=i+1;j<n;j++)
            {
                     if((v[j-1]<v[j]) && (!done))c++;
                     else done =true;
            }
            ans=max(ans,c);
         }
         return max(1,ans);
  }
   int foo1(vector<int>&v )
  {
    int n=v.size();
    int ans=0;
         for(int i=0;i<n;i++)
         {
            int c=1;
              bool done =false;
            for(int j=i+1;j<n;j++)
            {
                     if(v[j-1]>v[j] && (!done))c++;
                      else  done =true;
            }
            ans=max(ans,c);
         }
         return max(1,ans);
  }
    
    int longestMonotonicSubarray(vector<int>&v ) {
       
   return max(foo(v),foo1(v));
    }
};