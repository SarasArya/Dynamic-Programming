#include <iostream>
using namespace std;

/*We just need to implement the same algorithm in a table format.
So that the time complexity is limited to total * denomination  O(mn)*/

int count(int S[], int m , int n){
	int i, j, x, y;
	//We need table with total + 1 size as we are going bottom up from 0 to total
	int table[n+1][m];

	//table

	for(int i=0;i<m;i++){
		table[0][i] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			table[i][j] = 0;
		}
		
	}

	/*
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

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//If we take the denomination S[j]
			x = (i - S[j]) >=0 ? table[i - S[j]][j] : 0;

			//If we don't take the denomination S[j]
			y = (j >=1) ? table[i][j-1] : 0;
		
			table[i][j] = x + y;
		}
	}
	
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<"\n";
	}
	return table[n][m-1];
	
}

int main(){
	int n = 4; //total wanted
	int coin_array[] = {1,2,3};
	int m = sizeof(coin_array)/ sizeof(coin_array[0]);
	cout<<count(coin_array, m, n)<<"\n";
	return 0;
}