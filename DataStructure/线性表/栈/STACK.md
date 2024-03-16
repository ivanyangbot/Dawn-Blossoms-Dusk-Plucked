# **栈**

### **洗盘子55**

小止是餐厅里的洗碗工，她身边有一叠餐盘要洗。客人们吃完饭之后，要洗的盘子会放在这叠餐盘的顶端；而小止洗盘子的时候，总会取出这叠餐盘最顶上的盘子来洗。最开始桌子上没有餐盘。一位客人吃完饭了，依次把1、2、3这3个盘子放在了桌子上。现在小止取出了最顶端的3号盘子洗，洗完之后取出现在的顶端盘子2号。又有一个客人吃完了饭,依次放进了4、5这两个盘子。在这之后,小止依次洗完了5、4、1这3个盘子，结束了工作。

研究这一叠盘子,把“放盘子”和“取盘子”视为事件，那么在每一次事件之后,这叠盘子会是什么状态呢？请你自己画出示意图，画完就可以发现，越靠下的元素就越“顽固”，越靠上的元素就越容易改变。对于这叠餐盘，如果a比b早加入，那a一定比b后退出。**这种数据结构就是栈。** 栈是一种“后进先出(Last In First Out, LIFO)”的线性表，其限制是仅允许在表的一端进行插人和删除运算。

### “LAST IN FIRST OUT, LIFO”

### **1.**[栈（先进后出的数据结构）的设计与实现](https://www.dotcpp.com/course/102)

### **2.**[栈的基本操作及C语言代码实现](https://www.dotcpp.com/course/103)

### **3.**[栈数组与栈链表C语言代码实现](https://www.dotcpp.com/course/104)

#### 先通过数组简单了解栈的原理：

```c
//栈的实现
#include <iostream>
#include <stack>
using namespace std;
#define MAXN 1000k

int st[MAXN]; //一般使用数组来实现栈，栈底为stack[0]，栈顶为stack[p-1]
int p = 0;

void push(int x){ //入栈，将x放入栈顶
    if(p >= MAXN)
        cout<< "Stack overflow" << endl;
    else {
        st[p] = x;
        p++;
    }
}

void pop(){
    if(p == 0)
        cout<< "Stack is empty" << endl;
    else 
        p--;
}

int top(){
    if(p == 0){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else 
        return st[p - 1];
}

int main()
{
    cout<<"我们可以使用STL中的stack来实现栈"<< endl;
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<< s.top() << endl;
    s.pop();
    cout<< s.top() << endl;
    cout<< s.empty() << endl;
    cout<< s.size() << endl;
    s.emplace(4);   //emplace()和push()的区别是emplace()可以直接将元素放入栈中，而push()需要先创建一个元素再放入栈中
    cout<< s.top() << endl;

    return 0;
}
```

## 栈（先进后出的数据结构）的设计与实现

### **1. 栈的概念**

在开始前，请牢记这句话：栈是一种先进后出的数据结构。

栈（stack）是限定仅在表的一端进行操作的数据结构，请联系我们前文所学的，设想一个单链表我们只能够对其链表的表尾结点进行操作，而操作也只能够进行插入一个新的结点与删除最末尾的这个结点两个操作，而这样强限制性的‘链表’，就是我们所说的栈。

让我们重新理顺一下定义：栈是一个线性的数据结构，规定这个数据结构只允许在其中一端进行操作，并禁止直接访问除这一端以外的数据。

![栈](https://www.dotcpp.com/oj/ueditor/php/upload/image/20190722/1563785444676860.png "栈")

如图：栈就像一个放球的单管桶，只允许球从桶的开口这一端取出，并且球先放入桶中则后从桶中拿出。

### **2. 栈的结点设计**

#### **栈分为数组栈和链表栈，其区别是数组栈使用数组进行功能的模拟，实现较为快速和便利，而链表栈使用链表的思路去设计，实现较为麻烦，但是其稳定不易出错；在链表栈中又分为静态链表栈和动态链表栈，静态链表栈给定栈的空间大小，不允许超过存储超过给定数据大小的元素，而动态栈使用的是自动创建空间的方法进行创建，只要符合机器的硬件要求以及编译器的控制，其理论上是极大的。**

说了那么多，我们以链表栈的动态链表栈为例子，进行栈的设计，在后文直接以栈一名字称呼动态链表栈，这也是各类语言标准模板中栈的实现方式。

首先是栈的结点设计，我们可以设计出两个结构体，一个结构体Node表示结点，其中包含有一个data域和next指针。

![栈结点](https://www.dotcpp.com/oj/ueditor/php/upload/image/20190722/1563785508328006.png "栈结点")

其中data表示数据，其可以是简单的类型（如int,double等等），也可以是复杂的结构体（**struct**类型）；

next指针表示，下一个的指针，其指向下一个结点，通过next指针将各个结点链接。

目前的设计如同单链表，接下来，为这个进行限制性的设计，我们额外添加一个结构体，其包括了一个永远指向栈头的指针top和一个计数器count记录元素个数，（也可以设计成一个指针top和一个指针bottom分别指向栈头和栈尾）其主要功效就是设定允许操作元素的指针以及确定栈何时为空（count的方法是当count为0时为空，top和bottom方法就是两者指向同一个空间时为栈为空）

![栈结点2](https://www.dotcpp.com/oj/ueditor/php/upload/image/20190722/1563785513426310.png "栈结点2")

这里我采用的是top和count组合的方法。其代码可以表示为：

```c
//栈的节点设计
//单个节点设计，数据和下一个指针
typedef struct node{
  int data;
  struct node *next;
} Node;
//利用上面的节点创建栈，分为指向头节点的指针top和计数用的count
typedef struct stack{
  Node *top;
  int count;
} Linkstack
Linkstack *Stackcreate(){
  Linkstack *p = (Linkstack *)malloc(sizeof(Linkstack));
  if (p == NULL)
    return -1;
  p->top = 0;
  p->count = 0;
  return p;
}
```

### **3. 栈的基本操作—入栈**

如图：

![入栈操作](https://www.dotcpp.com/oj/ueditor/php/upload/image/20190722/1563785609411030.png "入栈操作")

入栈(push)操作时，我们只需要找到top所指向的空间，创建一个新的结点，将新的结点的next指针指向我们的top指针指向的空间，再将top指针转移，指向新的结点，即是入栈操作

其代码可以表示为：

```c
//入栈push
Linkstack *Pushstack(Linkstack *p, int elem) {
  if (p == NULL)
    return NULL;
  Node *tmp;
  tmp = (Linkstack *)malloc(sizeof(Linkstack));
  tmp->data = elem;  
  tmp->next = p->top;
  p->top = tmp;
  p->count++;
  return p;
}
```

## 栈的基本操作及C语言代码实现

### **1. 栈的基本操作—出栈**

如图：

![出栈操作](https://www.dotcpp.com/oj/ueditor/php/upload/image/20190722/1563785729466470.png "出栈操作")

出栈（pop）操作，是在栈不为空的情况下（注意一定要进行判空操作），将栈顶的元素删除，同时top指针，next向下进行移动即可的操作。

其代码可以表示为：

```c
// 出栈 pop
Linkstack *Popstack(Linkstack *p){
  Node *tmp;
  tmp = p->top;
  if (p->top == NULL) {
    cout << "错误，栈为空" << endl;
    return p;
  } else {
    p->top = p->top->next;
    free(tmp);
    p->count--;
    return p;
  }
}
```

### **2. 栈的基本操作—遍历**

栈的遍历相对而言比较复杂，由于栈的特殊性质，其只允许在一端进行操作，所以我们的遍历操作永远都是逆序的，其过程为，在栈不为空的情况下，一次从栈顶元素向下访问，直到指针指向空（即到栈尾）为结束。

其代码可以表示为：

```c
//遍历栈：输出栈中所有元素
int show_stack(Link_Stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("");
        printf("错误：栈为空");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
```

### **3. 快速栈实现--数组栈**

数组栈是一种更为快速的模拟实现栈的方法，所谓模拟，就是不采用真实的链表设计，转而采用数组的方式进行“模拟操作”，这是一种仿真类型的操作，其可以快速的帮助我们构建代码，分析过程，相应的实现起来也更加的便捷。

### **4. 配套题目推荐**

可以尝试的去利用栈的思维实现一下进制转换的题目

如十进制到八进制：[1055题](https://www.dotcpp.com/oj/problem1055.html)

十进制到二进制：[1192题](https://www.dotcpp.com/oj/problem1192.html)

或者可以尝试一下利用递归栈的方式，将栈去代替函数递归实现一些功能（注意，这将会是DFS搜索算法的理解基础）

如斐波那契数列：[1131题](https://www.dotcpp.com/oj/problem1131.html)

作业：

| 1055 | [二级C语言-进制转换](https://www.dotcpp.com/oj/problem1055.html)     |
| ---- | ----------------------------------------------------------------- |
| 1131 | [C语言训练-斐波纳契数列](https://www.dotcpp.com/oj/problem1131.html) |
| 1192 | [十-&gt;二进制转换](https://www.dotcpp.com/oj/problem1192.html)      |

## 栈数组与栈链表C语言代码实现

### **栈数组代码实现：**

```c++
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MANBA 1000

typedef struct stack{
  int data[MANBA];
  int top;
} stack;

stack *init(){
  stack *s = (stack *)malloc(sizeof(stack));
  if (s == NULL) {
    cout << "分配内存空间已满" << endl;
    exit(0);
  }
  memset(s->data, 0, sizeof(s->data));
  s->top = 0;
  return s;
}

void push(stack *s, int data){
  s->data[s->top] = data;
  s->top++;
}
void pop(stack *s){
  if (s->top) {
    s->data[s->top] = 0;
    s->top--;
  }
}
void printstack(stack *s){
  for(int n = s->top; n > 0; n--)
    cout << s->data[n];
}

int main(){
    stack *s=init();
    int input[5]={11,22,33,44,55}; 
    for(int i=0;i<5;i++){
        push(s,input[i]);
    }
    print_stack(s);
    pop(s);
    print_stack(s);
    return 0;
}
```

### **栈链表代码实现：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int count;
} Link_Stack;
 
Link_Stack *Creat_stack() {
    Link_Stack *p;
    p = (Link_Stack*)malloc(sizeof(Link_Stack));
    if(p == NULL){
        printf("创建失败，即将退出程序");
        exit(0);
    }
    p->count = 0;
    p->top = NULL;
    return p;
}
 
Link_Stack *Push_stack(Link_Stack *p, int elem)
{
    if (p == NULL)
        return NULL;
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data = elem;
    temp->next = p->top;
    p->top = temp;
    p->count++;
    return p;
}
 
Link_Stack *Pop_stack(Link_Stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("错误：栈为空");
        return p;
    }
    else
    {
        p->top = p->top->next;
        free(temp);
        //delete temp;
        p->count--;
        return p;
    }
}
 
int show_stack(Link_Stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("");
        printf("错误：栈为空");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
 
int main()
{ //用主函数测试一下功能
    Link_Stack *p;
    p = Creat_stack();
    int n = 5;
    int input[6] = {10,20,30,40,50,60};
    ///////////以依次入栈的方式创建整个栈////////////
    for(int i=0;i<n;i++){
        Push_stack(p, input[i]);
    }
    show_stack(p);
    ////////////////////出栈///////////////////////
    Pop_stack(p);
    show_stack(p);

    return 0;
}
```

#### **在STL库中，stack容器已经准备好了push(), pop(), top(), size(), empty()等函数操作，方便搭配我们搭配其他数据结构操作。这里面涉及许多暂未学到的知识，不在此处一一展开。**
