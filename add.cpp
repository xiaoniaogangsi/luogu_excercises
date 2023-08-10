#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[5001], b[5001];
    cin >> a >> b;
    int lena, lenb, lenc;
    lena = strlen(a);
    lenb = strlen(b);
    //将字符串转化为数字数组，从低位到高位存储
    int an[5001], bn[5001], cn[5001];
    for (int i=0; i<lena; i++){
        an[i] = a[lena-1-i] - '0';
    }
    for (int i=0; i<lenb; i++){
        bn[i] = b[lenb-1-i] - '0';
    }
    //位数低的前补零
    int maxlen;
    if (lena > lenb){
        for (int i=lenb; i<lena; i++){
            bn[i] = 0;
        }
        maxlen = lena;
    }else{
        for (int i=lena; i<lenb; i++){
            an[i] = 0;
        }
        maxlen = lenb;
    }
    //高精度加法，逐位相加
    for (int i=0; i<maxlen; i++){
        cn[i] = an[i] + bn[i];
    }
    //处理进位
    for (int i=0; i<maxlen+1; i++){    //结果最长为maxlen+1
        if (cn[i]>9){
            cn[i+1] += cn[i]/10;
            cn[i] %= 10;
        }
    }
    //确定位数
    lenc = maxlen+1;
    while (cn[lenc] == 0 && lenc>=0){
        lenc--;
    }
    lenc += 1;
    if (lenc==0){   //这意味着两个加数均为0，结果为0
        cout << 0;
        return 0;
    }
    //输出
    for (int i=lenc-1; i>=0; i--){
        cout << cn[i];
    }
    return 0;
}