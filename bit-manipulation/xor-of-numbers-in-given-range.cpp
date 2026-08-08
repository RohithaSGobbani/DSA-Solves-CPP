#include<bits/stdc++.h>
using namespace std;

int x(int n){
            if(n % 4 == 1) return 1;
            else if(n % 4 == 2) return n+1;
            else if(n % 4 == 3) return 0;
            else return n;

}
int findRangeXOR(int l,int r){
			//your code goes here
            return x(l-1)^x(r);
}

int main(){
	cout << findRangeXOR(4,7);
	return 0;
}
