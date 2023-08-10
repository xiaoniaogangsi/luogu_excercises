#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main(){
    string a[200];
    cin >> a[0];
    int n = a[0].size();

    int cnt = 0;
    int last = 0;
    for (int i=1; i<n; i++){
        cin >> a[i];
    }

    cout << n << ' ';
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j] - '0' == last){
                cnt++;
            }else{
                cout << cnt << ' ';
                last = 1-last;
                cnt = 1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}