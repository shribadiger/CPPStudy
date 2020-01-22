#include<iostream>
#include<vector>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
#define MAX 51

//Function to Display Data Points
int display_dataPoint(LL dp[MAX+1][MAX+1]) {
	for(int i=0;i<=MAX;i++) {
		for(int j=0;j<=MAX;j++) {
			std::cout<<"\t"<<dp[i][j];
		}
		std::cout<<"\n";
	}
}

int main()  {
	LL dataPoint[MAX+1][MAX+1];
	//initial value assign for each row
	for(int i=0;i<=MAX;i++) {
		dataPoint[0][i]=1;
		dataPoint[i][0]=1;
	}

	for(int i=1;i<=MAX;i++) {
		for(int j=1;j<=MAX;j++) {
			dataPoint[i][j]=dataPoint[i-1][j]+dataPoint[i][j-1];
		}
	}

	//display_dataPoint(dataPoint);
	int test_cases=0;
	cin>>test_cases;
	while(test_cases--) {
		int n,k,a=0,b=0;
		cin>>n;
		cin>>k;
		LL ans=1;
		vector<int> Arry(n);
		for(int i=0;i<n;i++) {
			cin>>Arry[i];
		}
		sort(Arry.begin(),Arry.end());
		if(k<n && Arry[k] == Arry[k-1]) {
			std::cout<<"\n Arry["<<k<<"] == Arry["<<k-1<<"]";
			for(int i=k-1;i>0;i--) {
				if(Arry[i] == Arry[k]) {
					std::cout<<"\n Arry["<<i<<"] == Arry["<<k<<"]";
					a++;
					std::cout<<"\n a: "<<a;
				}
			}
			for(int j=k;j<n;j++) {
				if(Arry[j] == Arry[k]) {
					std::cout<<"\n Arry["<<j<<"] == Arry["<<k<<"]";
					b++;
					std::cout<<"\n b: "<<b;
				}
			}

			std::cout<<"\n ans = dataPoint["<<a<<"]["<<b<<"] :"<<dataPoint[a][b];
			ans=dataPoint[a][b];
		}

		std::cout<<"\n Final Ans: "<<ans;
	}

	return 0;
}

