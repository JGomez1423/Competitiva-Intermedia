#include <bits/stdc++.h>
using namespace std;

class CheatingAfterTests{
      public:
            int cheat(vector<int> report){
                sort(report.begin(), report.end());
                int sum=0;
                if(report[0]>=10) {
                    if(report[0]>=90){
                        report[0]=99;
                    }else {
                        report[0]=90+(report[0]%10);
                        //cout<<"1st: "<<report[0]<<endl;
                    }
                    }else {pair<int,int> min ={report[0],0};
                    for(int i=0;i<report.size();i++){
                        if(report[i]>=90){
                            if(report[0]<report[i]%10){
                                report[0]=9;
                                break;
                            }else{
                                report[i]=99;
                                break;
                            }
                        }
                        if(report[i]>9 && report[i]<90){
                            report[i]=90+(report[i]%10);
                            break;
                        }
                        if(i==report.size()-1){
                            report[0]=9; 
                            break;
                        }
                    }
                }
                for(auto i:report){
                    sum+=i;
                    //cout<<i<<endl;
                }
                return sum;


            }

};
