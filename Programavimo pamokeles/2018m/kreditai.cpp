#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
void Skaito (int & n, int & g, int & k, int A[][100]);
int Did (int n, int A[]);
void Salinti (int nr, int & n, int A[]);
int main()
{
    int n, g, k, A[100][100], nr;

    Skaito (n, g, k, A);


	return 0;
}
void Skaito (int & n, int & g, int & k, int A[][100])
{
    int m, did = 0, x = 0;
    k = 0;
    ifstream df ("kreditai.txt");

    df >> n >> g;

   for (int i = 0; i < g; i++)
   {
       cout << endl;
       df >> m;
       for (int j = 0; j < m; j++) df >> A[i][j];
       did = Did(m, A[i]);
       if (n - A[i][did] >= 0 && x != 1)
       {
           n -= A[i][did];
           Salinti (did, m, A[i]);
           k++;
       }
       else x = 1;
       for (int j = 0; j < m; j++) cout << A[i][j] << " ";
   }

   cout << endl << k << " " << n;

   df.close();
}
int Did (int n, int A[])
{
   int d = 0;

    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[d]) d = i;
    }

    return d;
}
void Salinti (int nr, int & n, int A[])
{
    for (int i = nr; i < n; i++)
        A[i] = A[i+1];
        n--;
}
