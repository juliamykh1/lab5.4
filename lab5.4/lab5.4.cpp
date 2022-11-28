#include <iostream>
#include <cmath>

using namespace std;

double P0(int N)
{
	double P = 1;
	for (int K = N; K <= 25; K++)
	{
		P *= sqrt(1 + N * 1. / K);
	}
	return P;
}

double P1(int N, int K)
{
	if (K > 25)
		return 1;
	else
		return sqrt(1 + N * 1. / K) * P1(N, K + 1);
}

double P2(int N, int K)
{
	if (K < N)
		return 1;
	else
		return sqrt(1 + N * 1. / K) * P2(N, K - 1);
}

double P3(int N, int K, double t)
{
	t = t * sqrt(1 + N * 1. / K);
	if (K >= 25)
		return t;
	else
		return P3(N, K + 1, t);
}

double P4(int N, int K, double t)
{
	t = t * sqrt(1 + N * 1. / K);
	if (K <= N)
		return t;
	else
		return P4(N, K - 1, t);
}

int main()
{
	int N, K;

	cout << "N = "; cin >> N;

	K = N;
	cout << "(iter)        P0 = " << P0(N) << endl;
	cout << "(rec up ++)   P1 = " << P1(N, K) << endl;
	cout << "(rec up --)   P2 = " << P2(N, 25) << endl;
	cout << "(rec down ++) P3 = " << P3(N, K, 1) << endl;
	cout << "(rec down --) P4 = " << P4(N, 25, 1) << endl;

	return 0;
}
