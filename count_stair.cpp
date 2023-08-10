#include <bits/stdc++.h>
using namespace std;
int N;
int a[30000], b[30000];
int c[30000];
//去掉首项的斐波那契数列
int len(int* x){    //返回位数
    int i=30000-1;
    while (x[i]==0 && i>0){
        i--;
    }
    return i+1;
}

void fib(int N){
    if (N<=0){
        b[0] = 0;
    }else if (N==1){
        b[0] = 1;
    }else if (N==2){
        b[0] = 2;
    }else{
        a[0] = 1;
        b[0] = 2;
        for (int i=3; i<=N; i++){
            //a+b,结果保存在c中
            int maxlen = max(len(a), len(b));
            for (int j=0; j<maxlen; j++){
                c[j] = a[j]+b[j];
            }
            //处理进位
            for (int j=0; j<maxlen+1; j++){ //最多有maxlen+1位
                if (c[j]>9){
                    c[j+1] += c[j]/10;
                    c[j] %= 10;
                }
            }
            //a=b, b=c
            for (int i=0; i<30000; i++){
                a[i] = b[i];
                b[i] = c[i];
            }
        }

    }
    return;
}

int main(){
    cin >> N;
    for (int i=0; i<30000; i++){
        a[i] = b[i] = c[i] = 0;
    }
    fib(N);
    for (int i=len(b)-1; i>=0; i--){
        cout << b[i];
    }
    return 0;
}