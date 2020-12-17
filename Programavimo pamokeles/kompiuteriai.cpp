#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
void Skaito (int & n, string pav[], string nr[], double Kaina[]);
double Did (int n, double A[]);
void Atrinkti (int & n, string pav[], string nr[], double Kaina[], int & m, string pav1[], string nr1[], double Kaina1[]);
int main()
{
    int n, m;
    double Kaina[100], Kaina1[100];
    string nr[100], pav[100], nr1[100], pav1[100];
    Skaito (n, pav, nr, Kaina);
    Atrinkti (n, pav, nr, Kaina, m, pav1, nr1, Kaina1);

    for(int i = 0; i < m; i++) cout << nr1[i] << endl;

	return 0;
}
void Skaito (int & n, string pav[], string nr[], double Kaina[])
{
    ifstream df ("kompiuteriai.txt");

    df >> n;

    for (int i = 0; i < n; i++) df >> pav[i] >> nr[i] >> Kaina[i];

    df.close();
}
double Did (int n, double A[])
{
    int d = 0;

    for (int i = 1; i < n; i++)
        if (A[d] < A[i]) d = i;

    return A[d];
}
void Atrinkti (int & n, string pav[], string nr[], double Kaina[], int & m, string pav1[], string nr1[], double Kaina1[])
{
    m = 0;
   for (int i = 0; i < n; i++)
   {
       if (Kaina[i] >= Did(n, Kaina)*0.85 && Kaina[i] <= Did(n, Kaina)*1.15)
       {
           Kaina1[m] = Kaina[i];
           pav1[m] = pav[i];
           nr1[m] = nr[i];
           m++;
       }
   }
}
