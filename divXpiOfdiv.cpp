#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> pi(10000002,0);
vector<int> lp(10000002,0);
void calcTotientsAndLPD(){
    for(int i=1;i<10000002;++i){ 
        pi[i]=i;
        lp[i]=i;
    }
    for(int i=2;i<10000002;++i){
        if(pi[i]==i){
            for(int j=i;j<10000002;j+=i){
                pi[j] -= pi[j]/i;
                if(i<lp[j]) lp[j]=i;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    calcTotientsAndLPD();  //Least Prime Divisor
    ull t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int curLP,tmpLP;
        ull tmpSum,finalSum=1;
        while(n!=1){
            tmpSum=1;
            tmpLP = curLP = lp[n];
            while(!(n%curLP)){
                n/=curLP;
                tmpSum += ull(tmpLP)*pi[tmpLP];
                tmpLP *= curLP;
            }
            finalSum *= tmpSum;
        }
        cout<<finalSum<<'\n';
    }    
    return 0;
}