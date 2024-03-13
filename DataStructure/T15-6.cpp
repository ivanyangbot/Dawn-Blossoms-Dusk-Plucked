#include <iostream>
#include <stack>
using namespace std;


stack <int> s;

int operate(int a, int b, char ch){
    if (ch == '+') return b + a;
    if (ch == '-') return b - a;
    if (ch == '*') return b * a;
    if (ch == '/') return b / a;
    return 0;
}

int getnum(){
    s.pop();  //去掉点
    int num = 0;
    for(int i = 1; s.top() != '.'; i*=10){
        num += s.top() * i;
        s.pop();
    }
    return num;
}

int main(){
    string str;
    int a, b;
    cin >> str;
    for(int i = 0; str[i] != '@'; i++){
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') 
            s.push(operate(getnum(), getnum(), str[i]));
        else if (str[i] == '.')
            s.push(str[i]);
        else 
            s.push(str[i] - '0');
    }
    cout << s.top() << endl;
    return 0;
}

//stack <int> n;
//int s = 0, x, y;
//int main(){
//    char ch;
//    do{
//        ch = getchar();
//        if (ch >= '0' && ch <= '9')
//            s = s * 10 + ch - '0';
//        else if (ch == '.') {
//            n.push(s);
//            s = 0;
//        } else if (ch != '@') {
//            x = n.top();
//            n.pop();
//            y = n.top();
//            n.pop();
//            switch(ch) {
//                case '+': n.push(y + x); break;
//                case '-': n.push(y - x); break;
//                case '*': n.push(y * x); break;
//                case '/': n.push(y / x); break;
//             } 
//        }     
//    } while (ch != '@');
//    cout << n.top() << endl;
//    return 0;
//}