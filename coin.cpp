#include <iostream>
using namespace std;

int main(){
    int k; //days having coins
    cin >> k;
    int day = k;
    int sum = 0;
    int n = 1;
    while (day>0){
        for (int i=0; i<n; i++){
            if (day<=0){
                break;
            }
            sum += n;
            day--;
        }
        n++;
    }
    cout << sum;
}