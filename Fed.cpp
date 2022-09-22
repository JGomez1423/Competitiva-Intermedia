#include <bits/stdc++.h>
using namespace std;

struct palabra{
    string s;
    int rCount=0;
    int letras=0;
    palabra();
    palabra(string w){
        s=w;
        minimize();
        letrasCont();
        setrCount();

    }
    void setrCount(){
        for(int i=0;i<s.length();i++){
            if(s[i]=='r'){
                cout<<"entra: "<<i<<" "<< s[i]<<endl;
                rCount++;
            }
            
        }
    }
    void letrasCont(){
        letras=s.length();
    }
    void minimize(){
        for(int i=0;i<s.length();i++){
            if(s[i]>64 && s[i]<91){
                s[i]+=32;
            }
        }
    }
};
struct ensayo{
    vector<palabra> v;
    int rCountTotal=0;
    int letrasTotal=0;
    ensayo(vector<palabra> input){
        v=input;

    }
    void setTotales(){
        int rsum;
        int lsum;
        for(auto i: v){
            rsum+=i.rCount;
            lsum+=i.letras;
        }
        rCountTotal=rsum;
        letrasTotal=lsum;
    }

};
/*pair<palabra, palabra> parseSin(string s){
    string aux;
    pair<palabra, palabra> v(palabra(" "), palabra(" "));
    for(int i=0; i<s.length();i++){
        if(s[i]==' '){
            palabra p(aux);
            v.first=p;
            aux.clear();
        }else if(i==s.length()-1){
            aux+=s[i];
            palabra p(aux);
            v.second=p;
            aux.clear();
        }else aux+=s[i];
    }
    return v;
}*/
vector<palabra>  parse(string s){
    string aux;
    vector<palabra> v;
    for(int i=0; i<s.length();i++){
        
        if(s[i]==' '){
            palabra p(aux);
            v.push_back(p);
            aux.clear();
        }else if(i==s.length()-1){
            aux+=s[i];
            palabra p(aux);
            v.push_back(p);
            aux.clear();
        }else aux+=s[i];
    }
    return v;
}

bool worth(palabra p1, palabra p2){
    if(p1.rCount<p2.rCount){
        return true;
    }else if(p1.rCount==p2.rCount && p1.letras <= p2.letras){
        return true;
    }
    return false;
}
int main(){
    int n1, n2;
    string s;
    stringstream stream;
    unordered_set<palabra> diccionario;
    cout<<"ingrese numero de palabras del ensayo: "<<endl;
    cin>>n1;
    getchar();
    cout<<"ingrese ensayo: "<<endl;
    getline(cin, s);
    vector<palabra> ensayo = parse(s);
    cout<<"ingrese numero de sinonimos: "<<endl;
    cin>>n2;
    getchar();
    while(n2--){
        getline(cin, s);
        palabra p1;
        palabra p2;
        string aux;
        for(int i=0; i<s.length();i++){
            if(s[i]==' '){
                palabra p(aux);
                p1=p;
                aux.clear();
            }else if(i==s.length()-1){
                aux+=s[i];
                palabra p(aux);
                p2=p;
                aux.clear();
            }else aux+=s[i];
        }
        if(worth(p1, p2)){
            diccionario.insert(p1);
        }
    }
    cout<<"el tamaño del diccionario es: "<<diccionario.size()<<endl;
    /*
    cout<<"ingrese palabra: "<<endl;
    cin>>s;
    palabra pal(s);

    return 0;*/
}