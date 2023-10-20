#include <iostream>
#include <string>
using namespace std;

class dj
{
    int arr[10][10];

public:
    dj()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == j)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = 999;
                }
            }
        }
    }
    void get(int n);
    int min(int[], int[], int);
    void algo(int visit[], int dist[], int n);
};

void dj::get(int n)
{
    int i, j, d, e;
    cout << "enter the no. of entries you want to do::";
    cin >> e;
    for (int p = 0; p < e; p++)
    {
        cout << "enter the first vertex::";
        cin >> i;
        cout << "enter the second vertex::";
        cin >> j;
        cout << "enter the distance bet vertex::";
        cin >> d;
        if (i < n && j < n)
        {
            arr[i][j] = d;
            arr[j][i] = d;
        }
        else
        {
            cout << "there are only" << n << "vetices\n";
            i--;
        }
    }
}

int dj::min(int dist[], int visit[], int n)
{
    int key = 999;
    int r;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] != 1)
        {
            if (key > dist[i])
            {
                key = dist[i];
                r = i;
            }
        }
    }
    return r;
}

void dj::algo(int visit[], int dist[], int n)
{
    int s, m, source;
    string route[n];
    cout << "enter the starting vertex::";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        dist[i] = arr[s][i];
        visit[i] = 0;
    }
    visit[s] = 1;
    route[s] = to_string(s);
    source = s;
    for (int j = 1; j < n; j++)
    {
        m = min(dist, visit, n);
        visit[m] = 1;
        route[m] = route[source] + "->" + to_string(m);
        source = m;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] != 1)
            {
                if (dist[i] > (arr[m][i] + dist[m]))
                {
                    dist[i] = (arr[m][i] + dist[m]);
                }
            }
        }
    }
    cout << "\tVERTEX"
         << "\t"
         << "DIST"
         << "\tROUTE \n";
    for (int i = 0; i < n; i++)
    {

        cout << i << "\t" << dist[i] << "\t" << route[i] << endl;
    }
}

int main()
{
    int n;
    cout << "enter the no.of vertex::";
    cin >> n;
    int visit[n];
    int dist[n];
    dj obj;
    obj.get(n);
    obj.algo(visit, dist, n);
}