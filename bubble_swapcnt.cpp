#include <iostream>
using namespace std;
int n;
int a[10000];

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt=0;
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (a[j]>a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}