#include<iostream>
#include<iomanip>
using namespace std;
typedef struct
{  
	double per;
	int j; 
	int f;
}trade;
trade a[1005];
double pounds[1005];
int M,N;
#pragma region
void merges(int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	trade *L, *R;
	L = new trade[n1 + 1];
	R = new trade[n2 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = a[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[q + i + 1];
	L[n1].per = -100;
	R[n2].per = -100;
	for (int k = p, i = 0, j = 0; k <= r; k++)
	{
		if (L[i].per <= R[j].per)
		{
			a[k] = R[j];
			j++;
		}
		else
		{
			a[k] = L[i];
			i++;
		}
	}
}
void merge_sort(int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = (r + p) / 2;
		merge_sort( p, q);
		merge_sort(q + 1, r);
		merges(p, q, r);
	}
}
#pragma endregion
inline double get()
{
	double pounds=0,m=M;
	for (int i = 0; i < N; i++)
	{
		if (m <= 0) break;
		if (1.0*m / a[i].f>=1)
		{
			pounds += a[i].j;
			m = m - a[i].f;
		}
		else
		{
			pounds += 1.0*m / a[i].f*a[i].j;
			m = 0;
		}
	}
	return pounds;
}
int main()
{
	int m,n,cnt=0;
	while (cin >> m >> n)
	{
		if (m == -1 && n == -1) break;
		M = m;N = n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].j >> a[i].f;
			a[i].per = 1.0*a[i].j / a[i].f;
		}
		merge_sort(0, n - 1);
		pounds[cnt++] = get();
	}
	for (int i = 0; i < cnt; i++)
		cout<<fixed<<setprecision(3)<< pounds[i]<<endl;
//	system("pause");
	return 0;

}