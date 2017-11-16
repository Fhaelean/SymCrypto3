#include <iostream>
#include <vector>
#include <ctime>
#include <stdint.h>
using namespace std;

#define SIZEL1 33554431
#define SIZEL2 67108863 
#define SIZEL3 134217727 

int main()
{
	const int N = 219;
	const int C = 70;
	
	vector<int> Zi, L1, L2, L3;
	L1.push_back(1); L1.push_back(1); L1.push_back(1); L1.push_back(0); L1.push_back(0); L1.push_back(0); L1.push_back(1); L1.push_back(1); L1.push_back(1); L1.push_back(0);
	L1.push_back(0); L1.push_back(0); L1.push_back(1); L1.push_back(1); L1.push_back(1); L1.push_back(0); L1.push_back(0); L1.push_back(0); L1.push_back(1); L1.push_back(1);
	L1.push_back(1); L1.push_back(0); L1.push_back(0); L1.push_back(0); L1.push_back(1); L1.push_back(1); L1.push_back(1); L1.push_back(0); L1.push_back(0); L1.push_back(0);

	L2.push_back(1); L2.push_back(1); L2.push_back(1); L2.push_back(0); L2.push_back(0); L2.push_back(0); L2.push_back(1); L2.push_back(1); L2.push_back(1); L2.push_back(0);
	L2.push_back(0); L2.push_back(0); L2.push_back(1); L2.push_back(1); L2.push_back(1); L2.push_back(0); L2.push_back(0); L2.push_back(0); L2.push_back(1); L2.push_back(1);
	L2.push_back(1); L2.push_back(0); L2.push_back(0); L2.push_back(0); L2.push_back(1); L2.push_back(1); L2.push_back(1); L2.push_back(0); L2.push_back(0); L2.push_back(0); L2.push_back(1);

	L3.push_back(1); L3.push_back(1); L3.push_back(1); L3.push_back(0); L3.push_back(0); L3.push_back(0); L3.push_back(1); L3.push_back(1); L3.push_back(1); L3.push_back(0);
	L3.push_back(0); L3.push_back(0); L3.push_back(1); L3.push_back(1); L3.push_back(1); L3.push_back(0); L3.push_back(0); L3.push_back(0); L3.push_back(1); L3.push_back(1);
	L3.push_back(1); L3.push_back(0); L3.push_back(0); L3.push_back(0); L3.push_back(1); L3.push_back(1); L3.push_back(1); L3.push_back(0); L3.push_back(0); L3.push_back(0); L3.push_back(1); L3.push_back(1);

	int c;
	FILE * doc = fopen("ins.txt", "r");
	while (fscanf(doc, "%i", &c) != EOF)
	{
		if (c == '0')
			Zi.push_back(0);
		else
			Zi.push_back(1);
	}
	fclose(doc);

	int *res = new int;
	int *Xi = new int[SIZEL1];
	for (int i = 0; i < SIZEL1; i++)
	{
		Xi[i] = L1[0];
		*res = (L1[0] ^ L1[1] ^ L1[4] ^ L1[6]);
		rotate(L1.begin(), L1.begin() + 1, L1.end());
		L1[29] = *res;
	}
	
	int *resL1 = new int[2500];
	int count = 0;
	int SMN = (SIZEL1 - 220);
	for (int i = 0; i < SMN; i++)
	{
		int pr = 0;
		int R = 0;
		for (int j = 0; j < N; j++)
		{
			pr = Xi[i + j] ^ Zi[j];
			R += pr;
		}
		if (R < C)
		{
			for (int k = 0; k < N; k++)
			{
				resL1[count] = Xi[i + k];
				count++;
			}
		}
	}
	
	int *Yi = new int[SIZEL2];
	for (int i = 0; i < SIZEL2; i++)
	{
		Yi[i] = L2[0];
		*res = (L2[0] ^ L2[3]);
		rotate(L2.begin(), L2.begin() + 1, L2.end());
		L2[30] = *res;
	}

	int *resL2 = new int[2500];
	int count2 = 0;
	int SMN2 = (SIZEL2 - 220);
	for (int i = 0; i < SMN2; i++)
	{
		int pr = 0;
		int R = 0;
		for (int j = 0; j < N; j++)
		{
			pr = Yi[i + j] ^ Zi[j];
			R = R + pr;
		}
		if (R < C)
		{
			for (int k = 0; k < N; k++)
			{
				resL2[count2] = Yi[i + k];
				count2++;
			}
		}
	}

	int *Si = new int[SIZEL3];
	for (int i = 0; i < SIZEL3; i++)
	{
		Si[i] = L3[0];
		*res = (L3[0] ^ L3[1] ^ L3[2] ^ L3[3] ^ L3[5] ^ L3[7]);
		rotate(L3.begin(), L3.begin() + 1, L3.end());
		L3[31] = *res;
	}
	
	int SMN3 = (SIZEL3 - 220);
	int *Geffe = new int[220];
	int a, b, cc;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < SMN3; k++)
			{
				for (int z = 0; z < N; z++)
				{
					Geffe[z] = (Si[k + z] * resL1[i * 220 + z]) ^ (1 ^ Si[k + z]) * resL2[j * 220 + z];
				}
				if (Geffe[0] == Zi[0] && Geffe[1] == Zi[1] && Geffe[2] == Zi[2])
				{
					for (int l = 0; l < N; l++)
					{
						if (Geffe[l] != Zi[l])
							goto label;
					}
					a = i; b = j; cc = k;
				}
			label:;
			}
		}
	}

	freopen("out.txt", "w", stdout);
	cout << "L1: ";
	for (int i = 0; i < 29; i++)
		cout << resL1[i + a * 220];
	cout << "L2: ";
	for (int i = 0; i < 30; i++)
		cout << resL2[i + b * 220];
	cout << "L3: ";
	for (int i = 0; i < 31; i++)
		cout << Si[i + cc];
	fclose(stdout);
	
	return EXIT_SUCCESS;
}

