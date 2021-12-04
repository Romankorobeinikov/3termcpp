#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
    setlocale(0, "");
    int n;
    int inid;
    float mnem;
    float skip;
    set <int> id;
    set <int> :: iterator itid;
    set <int> ans;
    set <int> :: iterator itans;
    multimap <int, float> idmnem;
    multimap <int, float> :: iterator itidmnem;
    multimap <float, int> res;
    multimap <float, int> :: iterator itres;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> skip >> inid >> skip >> skip >> skip >> mnem >> skip;
        id.insert(inid);
        idmnem.insert(pair<int, float>(inid, mnem));
    }


    itid = id.begin();
    for (int i = 0; itid != id.end(); itid++, i++)
    {
        if(idmnem.count(*itid) > 1)
        {
            itidmnem = idmnem.find(*itid);
            float mi = itidmnem->second;
            float ma = itidmnem->second;
            for(int j = 0; j < idmnem.count(*itid); j++, itidmnem++)
            {
                if(itidmnem->second > ma){ma = itidmnem->second;}
                if(itidmnem->second < mi){mi = itidmnem->second;}
            }
            res.insert(pair<float, int>(ma - mi, *itid));
        }
    }
    if(res.size() > 0)
    {

    itres = res.begin();
    int i = 0;
    while(i < 3 && itres != res.end())
    {
        ans.insert(itres ->second);
        i++;
        itres++;
    }
    itans = ans.begin();
    for (int i = 0; itans != ans.end(); itans++, i++)
    {
        cout << *itans << ' ';
    }
    } else
    {
        cout << -1 << endl;
    }
}
