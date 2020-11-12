#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int N = 100;
int time[N][3];

//??????? ?????????
bool comparison(int h1, int m1, int s1, int h2, int m2, int s2)
{
	if (h1 < h2)
		return true;
	else if (h1 == h2 && m1 < m2)
		return true;
	else if (h1 == h2 && m1 == m2 && s1 < s2)
		return true;
	else
		return false;
}


int main()
{
	ifstream fin("INPUT.TXT");
	ofstream fout("OUTPUT.TXT");
	int n;
	fin >> n;

	//???? ??????
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			fin >> time[i][j];
	}

	//bubble sort
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			if (comparison(time[i][0], time[i][1], time[i][2], time[j][0], time[j][1], time[j][2])) 
			{
					swap(time[i][0], time[j][0]);
					swap(time[i][1], time[j][1]);
					swap(time[i][2], time[j][2]);
			}
	
	//????? ??????????????? ??????
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			fout << time[i][j] << " ";
		fout << endl;
	}
	return 0;

}
