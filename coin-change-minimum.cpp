/*The aim of the problem is to find in a set of coins which can give me the
denomination in a minimum number of coins
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

void minCoinChange(int coins [], int m, int total){
	int denom[total+1];
	int order[total+1];
	for(int i=0;i<total+1;i++){
		denom[i] = 999;
		order[i] = -1;
	}
	denom[0] = 0;
	long int result = 0;
	for (int i = 0; i < m; ++i)
	{
		for(int j=1;j<total+1;j++){
			if(j - coins[i] >= 0){
				if(1 + (denom[j - coins[i]]) < denom[j]){
					denom[j] = 1 + (denom[j - coins[i]]);
					order[j] = i;
				}
			}
		}
	}
	// for(int i=0;i<total+1;i++){
	// 	cout<<i << " "<<denom[i]<<"\n";
	// }
	// for(int i=0;i<total+1;i++){
	// 	cout<<i << " "<<order[i]<<"\n";
	// }
	cout<<"Total "<<total<<"\n";
	cout<<"Mininum coins required "<<denom[total]<<"\n";
	cout<<"Coins ";
	int i = total;
	while(total>0 && i>0){
		total = total - coins[order[i]];
		cout<<coins[order[i]]<<" ";
		i = i - coins[order[i]];

	}
	cout<<"\n";
}

int main(){
	int coins[] = {7,2,3,6};
	int total = 13;
	int size = sizeof(coins)/sizeof(coins[0]);
	minCoinChange(coins, size, total);
	return 0;
}
