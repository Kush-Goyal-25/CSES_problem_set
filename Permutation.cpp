#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;



int main(){
    ll n;
    cin>>n;
    vector<ll> ans(n);

    if(n==1){
        cout<<n;
    }
    else if(n<4){
        cout<<"NO SOLUTION";
    }
    else{
        for(ll i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(ll i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
    return 0;
}

