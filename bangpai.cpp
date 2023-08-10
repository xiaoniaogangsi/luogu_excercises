#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int n;
struct People{
    string name;
    string job;
    int job_rank;
    long long int contri;
    int level;
    int input_order;
};

bool a_g_b(const People& a, const People& b){
    if (a.contri == b.contri){
        return a.input_order < b.input_order;
    }else{
        return a.contri > b.contri;
    }
}

bool la_g_lb(const People& a, const People& b){
    if (a.job==b.job){
        if (a.level == b.level){
            return a.input_order < b.input_order;
        }else{
            return a.level > b.level;
        }
    }else{
        return a.job_rank < b.job_rank;
    }
}

int generate_jr(People a){
    int jr;
    if (a.job == "BangZhu"){
        jr = 0;
    }else if (a.job == "FuBangZhu"){
        jr = 1;
    }else if (a.job == "HuFa"){
        jr = 2;
    }else if (a.job == "ZhangLao"){
        jr = 3;
    }else if (a.job == "TangZhu"){
        jr = 4;
    }else if (a.job == "JingYing"){
        jr = 5;
    }else if (a.job == "BangZhong"){
        jr = 6;
    }
    return jr;
}

int main(){
    cin >> n;
    People members[n];
    for (int i=0; i<n; i++){
        cin >> members[i].name >> members[i].job >> members[i].contri >> members[i].level;
        members[i].input_order = i;
        members[i].job_rank = generate_jr(members[i]);
    }

    sort(members+3, members+n, a_g_b);

    for (int i=3; i<n; i++){
        if (i==3 || i==4) {members[i].job = "HuFa";}
        if (i>=5 && i<=8) {members[i].job = "ZhangLao";}
        if (i>=9 && i<=15) {members[i].job = "TangZhu";}
        if (i>=16 && i<=40) {members[i].job = "JingYing";}
        if (i>=41){members[i].job = "BangZhong";}
        members[i].job_rank = generate_jr(members[i]);
    }
    //Debug-------------------
    // cout << endl;
    // cout << "After assign jobs:" << endl;
    // for (int i=0; i<n; i++){
    //     cout << members[i].name << " " << members[i].job << " " << members[i].level << " " <<  members[i].job_rank << endl;
    // }
    // cout << endl;
    //------------------------
    sort(members+3, members+n, la_g_lb);
    
    for (int i=0; i<n; i++){
        cout << members[i].name << " " << members[i].job << " " << members[i].level << endl;
    }
    return 0;
}

/*# 帮贡排序

## 题目背景

在 absi2011 的帮派里，死号偏多。现在 absi2011 和帮主等人联合决定，要清除一些死号，加进一些新号，同时还要鼓励帮贡多的人，对帮派进行一番休整。

## 题目描述

目前帮派内共最多有一位帮主，两位副帮主，两位护法，四位长老，七位堂主，二十五名精英，帮众若干。

现在 absi2011 要对帮派内几乎所有人的职位全部调整一番。他发现这是个很难的事情。于是要求你帮他调整。

他给你每个人的以下数据：

他的名字（长度不会超过 $30$），他的原来职位，他的帮贡，他的等级。

他要给帮贡最多的护法的职位，其次长老，以此类推。

可是，乐斗的显示并不按帮贡排序而按职位和等级排序。

他要你求出最后乐斗显示的列表(在他调整过职位后)：职位第一关键字，等级第二关键字。

注意：absi2011 无权调整帮主、副帮主的职位，包括他自己的（这不是废话么..）

他按原来的顺序给你（所以，等级相同的，原来靠前的现在也要靠前，因为经验高低的原因，但此处为了简单点省去经验。）

## 输入格式

第一行一个正整数 $n$，表示星月家园内帮友的人数。

下面 $n$ 行每行两个字符串两个整数，表示每个人的名字、职位、帮贡、等级。

## 输出格式

一共输出 $n$ 行，每行包括排序后乐斗显示的名字、职位、等级。

## 样例 #1

### 样例输入 #1

```
9
DrangonflyKang BangZhu 100000 66
RenZaiJiangHu FuBangZhu 80000 60
absi2011 FuBangZhu 90000 60
BingQiLingDeYanLei HuFa 89000 58
Lcey HuFa 30000 49
BangYou3 ZhangLao 1000 1
BangYou1 TangZhu 100 40
BangYou2 JingYing 40000 10
BangYou4 BangZhong 400 1
```

### 样例输出 #1

```
DrangonflyKang BangZhu 66
RenZaiJiangHu FuBangZhu 60
absi2011 FuBangZhu 60
BingQiLingDeYanLei HuFa 58
BangYou2 HuFa 10
Lcey ZhangLao 49
BangYou1 ZhangLao 40
BangYou3 ZhangLao 1
BangYou4 ZhangLao 1
```

## 提示

各种职位用汉语拼音代替。

如果职位剩 $1$ 个，而有 $2$ 个帮贡相同的人，则选择原来在前的现在当选此职位。

另：
帮派名号：星月家园

帮主尊号：Dragonfly Kang

帮派ID：2685023

帮派等级：4

帮派人数：101/110

帮派技能：

星月家园资料，欢迎各位豆油加入^\_^

【数据范围】

对于 $10\%$ 的数据，保证 $n=3$。

对于 $40\%$ 的数据，保证各个人的帮贡均为 $0$。

对于 $100\%$ 的数据，保证 $3\leq n\leq 110$，各个名字长度$\leq30$，$0\leq$ 各个人的帮贡 $\leq1000000000$，
$1\leq$ 各个人等级 $\leq 150$。

保证职位必定为 $\texttt{BangZhu}$，$\texttt{FuBangZhu}$，$\texttt{HuFa}$，$\texttt{ZhangLao}$，$\texttt{TangZhu}$，$\texttt{JingYing}$，$\texttt{BangZhong}$ 之中的一个

保证有一名帮主，保证有两名副帮主，保证有一名副帮主叫 absi2011

不保证一开始帮派里所有职位都是满人的，但排序后分配职务请先分配高级职位。例如原来设一名护法现在设两名。

保证名字不重复。

【题目来源】

fight.pet.qq.com


absi2011 授权题目*/