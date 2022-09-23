    #include <bits/stdc++.h>
    using namespace std;

    string mini(string  s){
        string min=s;
            for(int i=0;i<s.length();i++){
                if(s[i]>64 && s[i]<91){
                    min[i]+=32;
                }
            }
            return min;
    }
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
                    rCount++;
                }
                
            }
        }
        void letrasCont(){
            for(int i=0;i<s.length();i++){
                if(s[i]>='a'&&s[i]<='z'){
                    letras++;
                }
                
            }
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
            setTotales();

        }
        void setTotales(){
            int rsum=0;
            int lsum=0;
            for(auto i: v){
                rsum+=i.rCount;
                lsum+=i.letras;
            }
            rCountTotal=rsum;
            letrasTotal=lsum;
        }

    };
    pair<string, string> parseSin(string s){
        string aux;
        pair<string,  string> v;
        for(int i=0; i<s.length();i++){
            if(s[i]==' '){
                //palabra p(aux);
                v.first=aux;
                aux.clear();
            }else if(i==s.length()-1){
                aux+=s[i];
                //palabra p(aux);
                v.second=aux;
                aux.clear();
            }else aux+=s[i];
        }
        return v;
    }
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

    bool worth(string w1, string w2){
        palabra p1(w1);
        palabra p2(w2);
        if(p2.rCount>p1.rCount){
            return false;
        }else if(p1.rCount==p2.rCount && p1.letras < p2.letras){
            return false;
        }
        return true;
    }
    pair<int, int> optimize(vector<palabra> v, unordered_map<string, string> d){
        for(int i=0; i<v.size();i++){
            auto id = d.find(v[i].s);
            if(id!=d.end()){
                auto idaux=d.find(id->second);
                while(idaux!=d.end()){
                    id=idaux;
                    idaux=d.find(id->second);
                }
                v[i]= palabra(id->second);
            }
        }
        ensayo e(v);
        pair<int, int> res(e.rCountTotal, e.letrasTotal);
        return res;

    }
    int main(){
        int n1, n2;
        string s;
        stringstream stream;
        unordered_map<string, string> diccionario;
        cin>>n1;
        getchar();
        getline(cin, s);
        vector<palabra> e = parse(s);
        pair<int, int> respuesta;

        cin>>n2;
        getchar();
        while(n2--){
            getline(cin, s);
            pair<string, string> p=parseSin(s);
            if(worth(p.first, p.second)){
                if(diccionario.find(mini(p.first))!=diccionario.end()){
                    if(worth(diccionario[mini(p.first)], p.second)){
                        diccionario[mini(p.first)]=mini(p.second);
                    }
                }else diccionario[mini(p.first)]=mini(p.second);
            }
        }
        if(diccionario.size()>0){
            respuesta = optimize(e, diccionario);
        }else{
            ensayo opt(e);
            respuesta.first= opt.rCountTotal; 
            respuesta.second= opt.letrasTotal;
        }
        cout<<respuesta.first<<" "<< respuesta.second<<endl;
        return 0;

    }
