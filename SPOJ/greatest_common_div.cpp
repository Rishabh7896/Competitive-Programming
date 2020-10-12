/*
    Problem Link: https://www.spoj.com/problems/GDCOFTI/
    Author: Rishabh Gautam
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	unsigned long long a,b,c; cin>>a>>b>>c;
	cout<<__gcd(a,__gcd(b,c));
	return 0;
} 