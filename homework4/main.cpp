#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	int citiesCnt;
	cin >> citiesCnt;

	int roads[100][100];
	for (int i = 0; i < citiesCnt; i++)
	{
		for (int j = 0; j < citiesCnt; j++)
		{
			cin >> roads[i][j];
		}
	}

	int count = 0, gardensCnt = 0;
	for (int j = 0; j < citiesCnt; j++)
	{
		for (int p = j + 1; p < citiesCnt; p++)
		{
			for (int k = 0; k < citiesCnt; k++)
			{
				if (roads[j][k] == 1)
				{
					if (roads[j][k] == roads[p][k])
					{
						count++;
					}
				}
			}
			if (count >= 2)
			{
				gardensCnt++;
				count = 0;
			}
		}
		count = 0;
	}

	gardensCnt = gardensCnt / 2;
	cout << gardensCnt << endl;
	return 0;
}
