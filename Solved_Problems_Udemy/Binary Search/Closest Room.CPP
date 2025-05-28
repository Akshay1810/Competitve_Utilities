#include <bits/stdc++.h>
using namespace std;

bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

vector<int> closestRoom(vector<vector<int>> rooms, vector<vector<int>> queries)
{
    for (int i = 0; i < queries.size(); i++)
    {
        queries[i].push_back(i);
    }
    sort(rooms.begin(), rooms.end(), comparator);
    sort(queries.begin(), queries.end(), comparator);
    int i = 0;
    set<int> st;
    vector<int> v(queries.size());

    for (auto q : queries)
    {
        int prefer = q[0];
        int minsize = q[1];
        int idx = q[2];

        while (i < rooms.size() and rooms[i][1] >= minsize)
        {
            st.insert(rooms[i++][0]);
        }

        if (st.size())
        {
            auto it = st.upper_bound(prefer);
            int res = (it != st.end()) ? abs(*it - prefer) : INT_MAX;
            int resRoonID = (it != st.end()) ? *it : INT_MAX;
            if (it != st.begin())
            {
                --it;
                if (abs(*it - prefer) <= res)
                {
                    resRoonID = *it;
                }
            }
            v[idx] = resRoonID;
        }
        else
        {
            v[idx] = -1;
        }
    }
    return v;
}
