class Solution {
public:
    int totalNumbers(vector<int>& d) {
        set<int>s;
        for(int i=0;i<d.size();i++)
           for(int j=i+1;j<d.size();j++)
            for(int z=j+1;z<d.size();z++)
              {
                  int a1=d[i]*100+d[j]*10+d[z];
                  if(a1/100!=0 && a1%2==0)s.insert(a1);
                  int a2=d[i]*100+d[z]*10+d[j];
                   if(a2/100!=0 && a2%2==0)s.insert(a2);
                  int a3=d[j]*100+d[z]*10+d[i];
                   if(a3/100!=0 && a3%2==0)s.insert(a3);
                  int a4=d[j]*100+d[i]*10+d[z];
                   if(a4/100!=0 &&  a4%2==0)s.insert(a4);
                  int a5=d[z]*100+d[j]*10+d[i];
                   if(a5/100!=0 && a5%2==0)s.insert(a5);
                  int a6=d[z]*100+d[i]*10+d[j];
                   if(a6/100!=0 && a6%2==0)s.insert(a6);

              }


              return (int)s.size();
    }
};