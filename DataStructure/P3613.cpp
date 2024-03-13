#include <iostream>
using namespace std;
int main(){
    int n, q;
    cin>>n>>q;
    int shelf[n][100000];
    for(int i=0; i<q; i++){
        int x, y, k;
        if(getchar()=='1'){
            cin>>x>>y>>k;
            shelf[x][y] = k;
        }
        else if(getchar()=='2'){
            cin>>x>>y;
            cout<<shelf[x][y]<<endl;
        }
    }
    return 0;
}