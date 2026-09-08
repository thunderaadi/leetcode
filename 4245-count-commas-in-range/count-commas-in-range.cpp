class Solution {
public:
    int countCommas(int n) {
        
        int count=0;
        int x=n;
         while(n!=0)
         {
             
                 count++;
             n/=10;
         }

         if(count>=4)
           return (x-1000+1);
           else
           return 0;
    }
};
