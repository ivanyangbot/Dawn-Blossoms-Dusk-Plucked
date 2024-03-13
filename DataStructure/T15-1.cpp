#include <iostream>
#include <vector>
using namespace std;

int n, m, tmp;
int main(){
    vector<int> stu; //建立一个一维vector
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        stu.push_back(tmp); //将输入的数加入到vector中
    }
    for (int i = 0; i < m; i++){
        cin >> tmp;
        cout << stu[tmp-1] << endl; //输出vector中的第tmp个数   
    }
    return 0;
}