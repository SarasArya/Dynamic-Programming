#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

/*We just need to implement the same algorithm in a table format.
So that the time complexity is limited to total * denomination  O(mn)
Now works for big integers as well. Added int64_t support 
to run it add --std=c++11 while compiling
*/


int64_t count(int S[], int m , int n){
	int64_t i, j, x, y;
	//We need table with total + 1 size as we are going bottom up from 0 to total
	int64_t table[n+1][m];

	//table

	for(i=0;i<m;i++){
		table[0][i] = 1;
	}

	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			table[i][j] = 0;
		}
		
	}

	/*
	After this 
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<"\n";
	}

	   m[0] m[1] m[2] 
    0   1    1    1
    1   0    0    0
    2   0    0    0
    3   0    0    0
    4   0    0    0
	*/

	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			//If we take the denomination S[j]
			x = (i - S[j]) >=0 ? table[i - S[j]][j] : 0;

			//If we don't take the denomination S[j]
			y = (j >=1) ? table[i][j-1] : 0;
		
			table[i][j] = x + y;
		}
	}
	
	ofstream fout("output.txt");
	if (!fout) {
    cerr << "Could not open file." << endl;
    return 1;
	}
	for (int i = 0; i <= n; ++i)
	{
		fout<<i<<" ";
		for (int j = 0; j < m; ++j)
		{
			fout<<table[i][j]<<" ";
		}
		fout<<"\n";
	}
	fout.close();
	return table[n][m-1];
	
}

int main(){
	int n = 250; //total wanted
	int coin_array[] = {8, 47, 13, 24, 25, 31, 32, 35, 3, 19, 40, 48, 1, 4, 17, 38, 22, 30, 33, 15, 44, 46, 36, 9, 20, 49};
	int m = sizeof(coin_array)/ sizeof(coin_array[0]);
	int64_t result = count(coin_array, m, n);
	cout<<result<<"\n";
	return 0;
}