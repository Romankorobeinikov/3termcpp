#include <iostream>
#include <set>

using namespace std;

int main() {
    int a;
    int n = 0;
    int s;
    set<int> line;
    cin >> a;
    for(int i=0; i<a; i++){
    cin >> s;
    line.insert(s);
    }
    n = line.size();
    cout << n;
    }
