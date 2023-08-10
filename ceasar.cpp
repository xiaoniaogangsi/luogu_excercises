#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    string org;
    string pwd = "";
    cin >> org;
    for (int i=0; i<org.size(); i++){
        if (org[i]+n>122){
            pwd += org[i] + n - 26;
        }else{
            pwd += org[i] + n;
        }
    }
    cout << pwd;
    return 0;
}