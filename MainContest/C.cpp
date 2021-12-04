#include <iostream>
#include <iomanip>
#include <iterator>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int d;
    int m;
    int y;
    int vsp;
    int zap;
    long full;
    set <int> dates;
    set <int> :: iterator it;
    map <long, int> data;
    cin>>zap;
    for(int i=0; i < zap; i++){
        cin>>setw(2)>>d;
        cin.ignore();
        cin>>setw(2)>>m;
        cin.ignore();
        cin>>setw(4)>>y;
        cin.ignore();
        cin>>vsp;
        full = y*10000 + m*100 + d;
        dates.insert(full);
        if(data.count(full)==1){
            if(data[full] < vsp){ data[full] = vsp;}
        } else {data[full] = vsp;}

    }

    cin>>zap;
    vector <int> maxvsp(zap);
    for(int i=0; i < zap; i++){
        cin>>setw(2)>>d;
        cin.ignore();
        cin>>setw(2)>>m;
        cin.ignore();
        cin>>setw(4)>>y;
        full = y*10000 + m*100 + d;
        it = dates.begin();
        maxvsp.at(i)=0;
        if(full < *it){ maxvsp.at(i) = 0; } else {
           while(*it < full && it != dates.end()){
           if( data[*it] > maxvsp.at(i)){maxvsp.at(i) = data[*it];}
           it++;

             }
           if( *it == full){
                if( data[*it] > maxvsp.at(i)){
                    maxvsp.at(i) = data[*it];}} else {
                if(it != dates.end()){
            it--;
           maxvsp.at(i) = data[*it];
            } else{if( data[*it] > maxvsp.at(i)){maxvsp.at(i) = data[*it];}}
             }

           }


        }
    for(int i=0; i < zap; i++){
           cout<<maxvsp[i]<<endl;
}






}


