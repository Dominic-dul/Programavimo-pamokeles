#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
void Skaito (int & n, int & m, int A[], int B[]);
int Iterpti (int nr, int x, int & n, int A[]);
void Rikiuoti (int n, int A[]);
void Naujas (int & n, int m, int A[], int B[]);
int main()
{
    int n, m, A[100], B[100], nr, x;

    Skaito (n, m, A, B);
    //Rikiuoti (m, B);
    Naujas(n, m, A, B);

    for (int i = 0; i < n; i++) cout << A[i] << " ";

	return 0;
}
void Skaito (int & n, int & m, int A[], int B[])
{
    ifstream df ("bankas.txt");

    df >> n >> m;

    for (int i = 0; i < n; i++) df >> A[i];

    for (int i = 0; i < m; i++) df >> B[i];

    df.close();
}
int Iterpti (int nr, int x, int & n, int A[])
{
    for (int i = n; i >= nr; i--)
        A[i] = A[i-1];
        A[nr] = x;
        n++;
}
void Rikiuoti (int n, int A[])
{
    int d = 0, t;

    for (int i = 0; i < n-1; i++)
    {
        d = i;
        for (int j = i+1; j < n; j++)
            if (A[j] > A[d]) d = j;
        t = A[i]; A[i] = A[d]; A[d] = t;
    }
}
void Naujas (int & n, int m, int A[], int B[])
{
    int x;
    for (int i = 0; i < m; i++)
    {
        x = 0;
        for (int j = 0; j < n && x != 1; j++)
            if (B[i] == A[j])
        {
            cout << j << endl;
            x = 1;
            Iterpti (j, B[i], n, A);
        }

    }
}
