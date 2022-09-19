#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	int n, m;
	scanf("%d:%d",&n,&m);
	int g = gcd(n, m);
	printf("%d:%d", n / g, m / g);
	return 0;
}