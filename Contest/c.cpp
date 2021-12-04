#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int maximum;
    int n = 0;
    string s;
    vector<string> > line;
    cin >> a;
    for(int i=0; i<a; i++){
    cin >> s;
    for(int j=0; j<sizeof(s)-1; j++)
    {
    char temp = s[j];
    s[j] = easytolower(temp);
    }
    line.insert(s);
    }
    n = line.size();
    multiset <string> :: iterator it = line.begin();
    for (int i = 1; it != line.end(); i++, it++) {
        cout << *it << " ";
    }
}
