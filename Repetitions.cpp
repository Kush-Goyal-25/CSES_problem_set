#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    string n;
    cin>>n;
 
    long long l = n.size();
    long long count=1;
    long long ans=0;
 
    for(int i=1;i<=l;i++){
        if(n[i]!=n[i-1]){
            count = 1;
        }
        else{
            count++;
        }
        ans = max(ans,count);
    }
    
    cout<<ans;
}