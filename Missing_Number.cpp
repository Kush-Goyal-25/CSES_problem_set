#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
 
    vector<long long> arr(n);
    long long total =0;
 
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
 
    long long sum = (n*(n+1))/2;
    cout<<sum-total;
}