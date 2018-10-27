// LadderProblem
#include <iostream>
using namespace std;

int ladder(int n,int k=3){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans += ladder(n-i,k);
	}

	return ans;
}

int topdown(int n,int *dp,int k=3){
	if(n==0){
		dp[n]=1;
		return 1;
	}

	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans += topdown(n-i,dp,k);
	}
	dp[n]=ans;
	return ans;
}


int bottomUP(int n,int k=3){
	int dp[1000]={0};
	dp[0]=1;

	for(int steps=1;steps<=n;steps++){
		for(int i=1;i<=k;i++){
			if(steps-i>=0){
				dp[steps] += dp[steps-i];
			}
		}
	}
	return dp[n];

}

int ways(int n,int k=3){
	int dp[1000]={0};

	dp[0]=dp[1]=1;

	for(int i=2;i<=n;i++){
		if(i-1-k>=0){
			dp[i]=2*dp[i-1]-dp[i-1-k];
		}
		else{
			dp[i]=2*dp[i-1];
		}
	}

	return dp[n];
}

int main(){

	int n,k;
	cin>>n;
	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=-1;
	}
	cout<<topdown(n,dp)<<endl;
	cout<<bottomUP(n)<<endl;
	cout<<ways(n)<<endl;
	cout<<ladder(n)<<endl;


	return 0;
}