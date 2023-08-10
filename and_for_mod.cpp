#include <iostream>
using namespace std;

int main()
{
    int a = 2325,i, da = 0, db = 0;
    
    cout<<"i  %  &"<<endl;
    for(i = 1; i<10;i++)
    {
        da = a%(i+1);
        db = a&i;
        if(!(da^db)) 
            cout<<i<<"  "<<da<<"  "<<db<<endl;
    }
    return 0;
}
