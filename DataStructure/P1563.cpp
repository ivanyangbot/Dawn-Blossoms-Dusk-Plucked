#include<bits/stdc++.h>
using namespace std;
struct node{
    int face;
    string occu;
}a[100007];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i].face>>a[i].occu;
    int now=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if((a[now].face + x) % 2 == 0)
            now=(now-y+n)%n;
        else
            now=(now+y)%n;
    }
    cout<<a[now].occu<<endl;
    return 0;
}