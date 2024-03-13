#include <iostream>
#include <vector>
using namespace std;

int n, q, opt, i, j, k; //柜子数，操作数，操作类型，格子号，物品
int main()
{
    cin >> n >> q;  //柜子数和操作数
    vector< vector<int> > locker(n + 1); //初始化，一共0~n号柜
    while(q--)
    {
        if(opt == 1){
            cin >> i >> j >> k; 
            if(locker[i].size() < j + 1) //如果格子不够大，就扩大
                locker[i].resize(j + 1, 0); //扩大到j+1大小,并且初始化为0
            locker[i][j] = k;
        }
        else {
            cin >> i >> j; //操作2，输出第j个柜子的钥匙
            cout << locker[i][j] << endl;
        }
    }
    return 0;
}