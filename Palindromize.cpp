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
                             if(s[j]==s[n-auxcont]){
                                 j++;
                                 auxcont++;
                             }else{
                                 pila.push(s[i]);
                                 break;
                             }
                             
                             
                         }if(n-auxcont<=j) break;
                     }else{
                        pila.push(s[i]);
                     }
                 }
                 vector<char> v;
                 for(int i=0;i<s.size();i++){
                    v.push_back(s[i]);
                 }

                 while(!pila.empty()) {
                        
                        v.push_back(pila.top());
                        pila.pop();
                    
                 }string sol(v.begin(), v.end());

                 return sol;
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
