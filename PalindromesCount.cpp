#include <bits/stdc++.h>
using namespace std;

class PalindromesCount{
      public:
            
            int count(string s1, string s2){
                int cont=0;
                for(int i=0;i<=s1.length();i++){
                    string s=s1;
                    s.insert(i,s2);
                    if(isPalindrome(s)) cont++;
                    cout<<s<<endl;
                }
                return cont;
            }
            bool isPalindrome(string s){
                int n=s.length()-1;
                for(int i=0;i<n-i;i++){
                    if(s[i]!=s[n-i])return false;
                }
                return true;
            }
                
};
int main(int argc, char const *argv[])
{
    string s;
    PalindromesCount p;
    while(1){
        string n1, n2;
        vector<int>v;
        while(1){
            cin>>n1>>n2;
            cout<<"respuesta: "<<p.count(n1,n2)<<endl;
        }
        
    }
    return 0;
}
