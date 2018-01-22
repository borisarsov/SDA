#include <vector>
#include <iostream>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int pre[100001];
int pos[100001];
int dfsnumber = 1;

const int MOVE_TOWARDS = 0;
const int MOVE_AWAY = 1;

void dfs(int node)
{
	visited[node] = true;
	pre[node] = dfsnumber++;

	for (int adj=0:adj<graph[node])
	{
		if (!visited[adj])
		{
			dfs(adj);
		}
	}

	pos[node] = dfsnumber++;
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr);*/

	int nodes;
	cin >> nodes;

	for (int i = 0; i < nodes - 1; ++i)
	{
		int parent, child;
		cin >> parent >> child;
		graph[parent].push_back(child);
	}

	dfs(1);

	int queriesCount;
	cin >> queriesCount;

	for (size_t i = 0; i < queriesCount; i++)
	{
		int move, startNode, endNode;
		cin >> move >> endNode >> startNode;

		if (move == MOVE_TOWARDS)
		{
			cout << (pre[startNode] > pre[endNode] && pos[startNode] < pos[endNode] ?
				"Yes\n" : "No\n");
		}
		else if (move == MOVE_AWAY)
		{
			cout << (pre[startNode] < pre[endNode] && pos[startNode] > pos[endNode] ?
				"Yes\n" : "No\n");
		}
	}

	return 0;
}
