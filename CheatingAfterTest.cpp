#include <bits/stdc++.h>
using namespace std;

class CheatingAfterTests{
      public:
             int cheat(vector<int> report){
                int flag=0;
                int sum=0;
                pair<int,int> min = {109,0};
                pair<int,int> min2 = {109,0};
                for(int i=0;i<report.size();i++){
                    if(report[i]>=90&&report[i]<min2.first){
                        min2={report[i],i};
                    }else if(flag==0&&report[i]<min.first){
                        min={report[i],i};
                        if(report[i]>=10) flag=1;
                    }else if(report[i]<min.first && report[i]>10){
                        min={report[i],i};
                    }  
                    /*cout<<i<<"  min: "<<min.first<<endl;
                    cout<<i<<"  min2: "<<min2.first<<endl;*/

                }

                if(flag){
                    if(report[min.second]<90){
                        report[min.second]=90+(min.first%10);
                    }else report[min.second]=99;
                }else{
                    if(min.first<min2.first%10){
                        report[min.second]=9;
                    }else{
                        report[min2.second]=99;
                    }
                    }
                for(auto i:report){
                    sum+=i;
                }
                return sum;
             }
             
};
int main(int argc, char const *argv[])
{
    string s;
    CheatingAfterTests p;
    cout<<"respuesta: "<<p.cheat({4, 5, 7, 2})<<endl;
    return 0;
}
