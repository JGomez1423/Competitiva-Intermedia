#include <bits/stdc++.h>
using namespace std;

class CheatingAfterTests{
      public:
            
            int cheat(string s){
                bitset<10> b;
                string sol;
                int flag=0;
                for(int i=0; i<s.length();i++){
                    switch (s[i]){
                        case '1':
                            b[0]=1;
                            cout<<"entra 1"<<endl;
                            break;
                            
                        case '0':
                            b[1]=1;
                            cout<<"entra 0"<<endl;
                            break;
                            
                        case '2':
                            b[2]=1;
                            cout<<"entra 2"<<endl;
                            break;
                        case '3':
                            b[3]=1;
                            cout<<"entra 3"<<endl;
                            break;
                        case '4':
                            b[4]=1;
                            cout<<"entra 4"<<endl;
                            break;
                        case '5':
                            b[5]=1;
                            cout<<"entra 5"<<endl;
                            break;
                        case '6':
                            b[6]=1;
                            cout<<"entra 6"<<endl;
                            break;
                        case '7':
                            b[7]=1;
                            cout<<"entra 7"<<endl;
                            break;
                        case '8':
                            b[8]=1;
                            cout<<"entra 8"<<endl;
                            break;
                        case '9':
                            b[9]=1;
                            cout<<"entra 9"<<endl;
                            break;
                    }
                }
                for(int i=0;i<10;i++){
                    if(i==0&&b[i]==0){
                        char aux= '1'; 
                        sol+=aux;
                        flag=2;
                    }else if(flag!=1&&b[i]==0){
                        if(i==1){
                            if (flag>1){
                                char aux= '0';
                                sol+=aux;
                                cout<<"in2"<<endl;
                            }else flag=1;
                        }else{
                            char aux= i+'0'; 
                            sol+=aux;
                        }
                    }else if(flag==1&&b[i]==0){
                        char aux= i+'0'; 
                        sol+=aux;
                        aux='0';
                        sol+=aux;
                        flag=0;
                        cout<<"in"<<endl;
                    }
                    cout<<"i:"<<i<<"flag: "<<flag <<"sol "<<sol<<endl;
                }
                if(flag==1) return 0;
                return stoi(sol);
            }
                
};
int main(int argc, char const *argv[])
{
    string s;
    CheatingAfterTests p;
    while(1){
        string n;
        vector<int>v;
        while(cin>>n){
            cout<<"respuesta: "<<p.cheat(n)<<endl;
        }
        
    }
    return 0;
}
