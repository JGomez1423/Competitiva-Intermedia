#include <bits/stdc++.h>
using namespace std;

class Palindromize{
      public:
             string minAdds(string s){
                 int aux,n,auxcont;
                 n=s.size()-1;
                 aux= 0;
                 auxcont=1;
                 
                 stack<char> pila;
                 for(int i=0;i<s.size();i++){
                     if(s[n]==s[i]){
                         aux+=1;
                         int j=i+1;
                         while(n-auxcont>j){
                             //cout<<s[j]<<"  "<<s[n-auxcont]<<endl;
                             if(s[j]==s[n-auxcont]){
                                 j++;
                                 auxcont++;
                             }else{
                                 pila.push(s[i]);
                                 auxcont=1;
                                 break;
                             }
                             
                             
                         }if(n-auxcont<=j) break;
                     }else{
                        pila.push(s[i]);
                     }
                 }

                 vector<char> v;
                 while(!pila.empty()) {
                        
                        v.push_back(pila.top());
                        pila.pop();
                    
                 }string sol(v.begin(), v.end());
                 s.append(sol);


                 return s;
             }
             
};
int main(int argc, char const *argv[])
{
    string s;
    Palindromize p;
        while(cin>>s){
        cout<<p.minAdds(s)<<endl;
        }
        return 0;
}
