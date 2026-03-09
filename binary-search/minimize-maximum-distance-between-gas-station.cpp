#include<bits/stdc++.h>
using namespace std;

//Brute
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n = arr.size();
	vector<int> howmany(n-1,0);
	for(int gasS = 1; gasS <= k; gasS++){
		long double maxSection = -1;
		int maxInd = -1;
		for(int i = 0; i < n-1; i++){
			long double diff = arr[i+1] - arr[i];
			long double sectionLength = diff / (long double)(howmany[i]+1);
			if(sectionLength > maxSection){
				maxSection = sectionLength;
				maxInd = i;
			}
		}
		howmany[maxInd]++;
	}
	long double maxAns = -1;
	for(int i = 0; i < n-1; i++){
		long double diff = arr[i+1] - arr[i];
		long double sectionLength = diff/(long double)(howmany[i]+1);
		maxAns = max(maxAns, sectionLength);
	}
	return maxAns;
}

//Better
double minimiseMaxDistanceBetter(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howmany(n-1,0);
    priority_queue<pair<long double, int>> pq;
    for(int i = 0; i < n-1; i++){
        pq.push({arr[i+1] - arr[i],i});
    }
    for(int gasS = 1; gasS <= k; gasS++){
        auto tp = pq.top();pq.pop();
        int secInd = tp.second;
        howmany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSeclen = iniDiff / (long double)(howmany[secInd] + 1);
        pq.push({newSeclen, secInd});
    }
    return pq.top().first;
}

//Optimal
int countofgasstation(long double dist, vector<int> &arr){
    int cnt = 0;
    for(int i =1; i < arr.size(); i++){
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((arr[i] - arr[i-1] / dist) == numberInBetween * dist){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistanceBS(vector<int> &arr, int k){
    int n = arr.size();
    long double low = 0, high = 0;
    for(int i = 0; i < n-1; i++){
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = low + (high - low) / (2.0);
        int cnt = countofgasstation(mid, arr);
        if(cnt > k){
            low = mid;
        }else{
            high = mid;
        }
    }
    return high;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << minimiseMaxDistanceBS(arr, k);
    return 0;
}