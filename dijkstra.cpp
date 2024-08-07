#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=510;

int n,m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main()
{
	cin >> n >> m;
	
	memset(g,0x3f,sizeof g);
	
	while(m--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b]=min(g[a][b],c);
	}
	int t=dijkstra();
	cout << t << endl;
	return 0;
}

