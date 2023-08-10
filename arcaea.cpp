#include <bits/stdc++.h>
#include <cstring>
#include <iomanip>
using namespace std;
//洛谷 U131424 [Arcaea] 查分器
int main(){
    //读入曲名（整行）
    string name;
    getline(cin, name);
    //分数
    double p, a, b, c; //p为总Pure，a为大Pure数量，b为Far数量，c为Lost数量
    double d;   //d为铺面定数
    cin >> p >> a >> b >> c;
    cin >> d;
    double PM = 10000000;
    double EX = 9800000;
    double AA = 9500000;
    double A = 9200000;
    double notes = p + b + c; //总物量
    double note_score = PM/notes;   //单个note的分数
    double score;
    if (b==0 && c==0){ //PM
        score = PM + a;
    }else{ //not PM
        score = p*note_score + 0.5*b*note_score + a;
    }
    //PTT
    double ptt;
    if (score >= PM){
        ptt = d + 2.00;
    }else if (score >= EX){
        ptt = d + 1.00 + (1.00/(PM-EX))*(score-EX);
    }else{
        ptt = d + (1.00/(EX-AA))*(score-AA);
        if (ptt < 0.00){
            ptt = 0.00;
        }
    }
    //输出
    int int_score = (int) score;
    cout << setw(8) << setfill('0') << int_score << endl;
    cout << fixed << setprecision(2) << ptt;
    return 0;
}