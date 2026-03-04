#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<vector<pair<int, int>>> par;
    UnionFind(int H, int W) : par(H, vector<pair<int, int>>(W, make_pair(-1, -1))) {}

    pair<int, int> root(int h, int w)
    {
        if (par[h][w] == make_pair(h, w))
            return make_pair(h, w);
        return par[h][w] = root(par[h][w].first, par[h][w].second);
    }

    void paint(int h, int w)
    {
        par[h][w] = make_pair(h, w);
    }

    void unite(int h1, int w1, int h2, int w2)
    {
        pair<int, int> r1 = root(h1, w1);
        pair<int, int> r2 = root(h2, w2);
        if (r1 == r2)
            return;
        par[r1.first][r1.second] = r2;
    }

    bool same(int h1, int w1, int h2, int w2)
    {
        pair<int, int> r1 = root(h1, w1);
        pair<int, int> r2 = root(h2, w2);
        return r1 == r2;
    }

    bool painted(int h, int w)
    {
        if (par[h][w] == make_pair(-1, -1))
            return false;
        else
            return true;
    }
};

int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;
    UnionFind tree(H + 2, W + 2);
    bool enabled = true;
    int q, ra, ca, rb, cb;

    for (int i = 0; i < Q; i++)
    {
        enabled = true;
        cin >> q;
        if (q == 1)
        {
            cin >> ra >> ca;
            tree.paint(ra, ca);
            if (tree.painted(ra - 1, ca))
                tree.unite(ra, ca, ra - 1, ca);
            if (tree.painted(ra + 1, ca))
                tree.unite(ra, ca, ra + 1, ca);
            if (tree.painted(ra, ca - 1))
                tree.unite(ra, ca, ra, ca - 1);
            if (tree.painted(ra, ca + 1))
                tree.unite(ra, ca, ra, ca + 1);
        }
        else
        {
            cin >> ra >> ca >> rb >> cb;
            if (tree.painted(ra, ca) && tree.painted(rb, cb) && tree.same(ra, ca, rb, cb))
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
            cout << endl;
        }
    }

    return 0;
}