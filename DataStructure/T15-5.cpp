#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char> s;
int num;
char trans(char a){  //根据后面的括号找到前面的括号
    if (a == ')') return '(';
    if (a == ']') return '[';
    if (a == '}') return '{';
    return '\0';
}

int main(){
    cin >> num;
    string str;
    getchar();  //读取换行符，使用cin读入一个独占的数字之后，其读入指针在这一行的末尾，如果再使用getline读入一行字符串时，只会读到空串。
    while(num--){
        while(!s.empty()) s.pop();  //清空栈
        getline(cin, str);
        for (int i = 0; i < str.length(); i++){
            if(s.empty()) s.push(str[i]);
            if(trans(str[i]) == s.top()) s.pop();
            else s.emplace(str[i]);
        }
        if(s.empty()) cout << "Yes." << endl;
        else cout << "No." << endl;
    }
    return 0;
}