#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<string>
#include<list>


using namespace std;


#define ll long long
#define input scanf
#define output printf 
#define Loop while
#define echo cout
#define ret return
#define MAX 999999999999999999
#define MIN 0
#define PI 3.1415

int main(int argc, char** argv) {
	
	//freopen("c.txt","w",stdout);
	int t;
	cin>>t;
	int n,w;
	while(t--)
	{
		cin>>n>>w;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a.begin(),a.end());
		ll sum=0;
		int count=0;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
			if(sum>w)
			break;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
