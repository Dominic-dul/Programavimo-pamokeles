#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
void Skaito (int & n, string pav[], int A[]);
int Did (int n, int A[]);
int Maz (int n, int A[]);
void Raso (int n, string pav[], int A[]);
int main()
{
    int n, A[100];
    string pav[100];

    Skaito (n, pav, A);
    Raso (n, pav, A);

	return 0;
}
void Skaito (int & n, string pav[], int A[])
{
    ifstream df ("salys.txt");

    int x, y;

    df >> n;

    for (int i = 0; i < n; i++)
    {
        df >> pav[i];
        df >> x >> y;
        A[i] = x-y;
    }

    df.close();
}
int Did (int n, int A[])
{
    int d = 0;
    for (int i = 1; i < n; i++)
        if (A[i]>A[d]) d = i;

    return d;
}
int Maz (int n, int A[])
{
    int m = 0;

    for (int i = 1; i < n; i++)
        if (A[i] < A[m]) m = i;

    return m;
}
void Raso (int n, string pav[], int A[])
{
    ofstream rf ("salys_res.txt");

    rf << "Didziausias: " << pav[Did(n, A)] << " " << A[Did(n, A)] << endl;
    rf << "Maziausias: " << pav[Maz(n, A)] << " " << A[Maz(n, A)] << endl;

    rf << "Bendras sarasas: " << endl;

    for (int i = 0; i < n; i++) rf << pav[i] << " " << A[i] << endl;

    rf.close();
}
