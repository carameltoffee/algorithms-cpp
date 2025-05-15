#include<iostream>
using namespace std;

int main(){
    string s;cin>>s;
    int a=1,b=s[0]!='0',c;
    for(int i=1;i<s.size();i++){
        c=0;
        if(s[i]!='0')c+=b;
        int x=(s[i-1]-'0')*10+(s[i]-'0');
        if(x>=10&&x<=26)c+=a;
        a=b;b=c;
    }
    cout<<b;
}
