#include <iostream>
using namespace std;

//here S is the coin array, m is the size of coin array and n is the desired denomination. 
int count(int S [], int m, int n){
	//Case 1 : n==0 It means we have a solution
	cout<<m<<" "<<n<<"\n";
	if(n==0){
		return 1;
	}
	
	//Case 2 : n<0 It means a solution is not possible return 0
	if(n<0){
		return 0;
	}

	//Case 3 : m <= 0 && n>=1 means coins are finished and the sum is >=1. No solution possible
	if(m<=0 && n>=1){
		return 0;
	}

	//Case 4 : Either we choose the coin or not. 

	return count(S, m-1, n) + count(S, m, n-S[m-1]);
}

int main(){
	int n = 4; //denomination wanted
	int coin_array[] = {1,2,3};
	int m = sizeof(coin_array)/ sizeof(coin_array[0]);
	cout<<count(coin_array, m, n)<<"\n";
	return 0;
}