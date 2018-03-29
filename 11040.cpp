#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<math.h>
#include <utility>
#include <sstream> 
#include<bitset>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;

#define PI acos(-1)
#define E 2.718281828459

std::bitset<2250> bs; // 10^7 + small extra bits should be enough for most prime-related problems
std::vector<ll> primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
          int sieve_size = upperbound + 1; // add 1 to include upperbound
           bs.reset(); bs.flip(); // set all numbers to 1
            bs.set(0, false); bs.set(1, false); // except index 0 and 1
          for (ll i = 2; i <= sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i! 
          for (ll j = i * i; j <= sieve_size; j += i) bs.set((size_t)j, false);
           primes.push_back((int)i);
    }
} 
vi primeFactors(ll N) {
      vi factors;          // vi "primes" (generated by sieve) is optional
      ll PF_idx = 0, PF = primes[PF_idx]; // using PF = 2, 3, 4, ..., is also ok.
      while ((PF * PF <= N)) { // stop at sqrt(N), but N can get smaller
        while (N % PF == 0) { 
		N /= PF; factors.push_back(PF); } // remove this PF
            PF = primes[++PF_idx]; // only consider primes!
            }
          if (N != 1) factors.push_back(N); // special case if N is actually a prime
      return factors;
}
int gcd(int a, int b)
{ 
       return (b == 0 ? a : gcd(b, a % b)); 
}

int main(int argc, char** argv) {
	//freopen("c.txt","w",stdout);
	int t,x;
	cin>>t;
	int n,I=1;
	while(t--)
	{
		int A[9][9];
		memset(A,-1,sizeof(A));
		vector<int> a[10];
		a[0].push_back(4);
		a[2].push_back(3);
		a[2].push_back(5);
		a[4].push_back(2);a[4].push_back(4);a[4].push_back(6);
		a[6].push_back(1);a[6].push_back(3);a[6].push_back(5);a[6].push_back(7);
		a[8].push_back(0);a[8].push_back(2);a[8].push_back(4);a[8].push_back(6);a[8].push_back(8);
		vector<int> answer;
		for(int i=0,k=0;i<5;i++,k+=2)
		{
			for(int j=0;j<=i;j++)
			{
				cin>>A[k][a[k][j]];
			}
		}
		/*for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cout<<A[i][j]<< " ";
			}
			cout<<endl;
		}*/
		
		for(int i=0;i<9;i+=2)
		{
			if(i==8)
			continue;
			
			for(int j=0;j<9;j++)
			{
				if(A[i][j]!=-1)
				{
					int temp=A[i][j]-(A[i+2][j-1]+A[i+2][j+1]);
					temp/=2;
					A[i+2][j]=temp;
					//cout<<A[i][j]<<" "<<temp<<endl;
					answer.push_back(A[i+2][j-1]+temp);answer.push_back(A[i+2][j+1]+temp);
					j++;
				}
			}
		}
		//cout<<"--------------------------------------------\n";
		int J=0;
		for(int i=0;i<9;i++)
		{
			if(i%2!=0)
			{
				for(int I=1;I<=i+1;I++,J++)
				{
					if(I!=1)cout<<" ";
					cout<<answer[J];
				}
				cout<<endl;
				continue;
			}
			int c=0;
			for(int j=0;j<9;j++)
			{
				if(A[i][j]==-1)continue;
				if(c!=0)cout<<" ";
				cout<<A[i][j];
				c++;
			}
			cout<<endl;
		}
	}
   return 0;
}
