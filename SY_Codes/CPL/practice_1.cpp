#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ans;

void subsetCreator(vector<int> &q, int index)
{
    if (index == q.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        ans.push_back(q[index]);
        subsetCreator(q, index + 1);
        ans.pop_back();
        subsetCreator(q, index + 1);
    }
}

int32_t main()
{
    
    int n;
    cin >> n;
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    subsetCreator(q, 0);
}