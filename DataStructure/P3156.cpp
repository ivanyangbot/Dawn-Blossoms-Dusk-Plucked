#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int id[n], num[m];
    for(int i=0; i<n; i++){
        cin>>id[i];
    }
    for(int i=0; i<m; i++){
        cin>>num[i];
    }
    for(int i=0; i<m; i++){
        cout<<id[num[i]-1]<<endl;
    }
    return 0;
}