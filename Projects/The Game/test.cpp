#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v;
    long int d=0;
    char x;
    int n=0;
    while(true)
    {
        cin.get(x);
        if(x==10)
            break;
        v.push_back(int(x-48));
        n++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i];
        if (i%2){d-=v[i];}else{d+=v[i];}
    }
    cout<<endl<<n<<endl<<d;

}
