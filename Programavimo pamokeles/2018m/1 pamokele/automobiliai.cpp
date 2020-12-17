#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
struct modeliukas
{
    int kiekis;
    double kaina;
};
//-------------------------------------------------------
void Skaito (int & n, modeliukas A[]);
double Kiekis (int n, modeliukas A[]);
double Kaina (int n, modeliukas A[]);
double Vidutine (double a, double b);
void Raso (int n, modeliukas A[]);
int main()
{
    int n, a, b;
    modeliukas A[100];

    Skaito(n, A);
    Raso(n, A);

	return 0;
}
void Skaito (int & n, modeliukas A[])
{
    ifstream df ("modeliukai.txt");

    df >> n;

    for (int i = 0; i < n; i++)
    {
        df >> A[i].kaina >> A[i].kiekis;
    }


    df.close();
}
double Kiekis (int n, modeliukas A[])
{
    double sum = 0;

    for (int i = 0; i < n; i++) sum += A[i].kiekis;

    return sum;
}
double Kaina (int n, modeliukas A[])
{
    double sum = 0;

    for (int i = 0; i < n; i++) sum += A[i].kaina;

    return sum;
}
double Vidutine (double a, double b)
{
    return a/b;
}
void Raso (int n, modeliukas A[])
{
    ofstream rf ("modeliukai_rez.txt");

    cout << Kiekis (n, A) << endl << Kaina(n, A);

    rf <<  fixed << setprecision(2) << Vidutine(Kaina(n, A), Kiekis(n, A));

    rf.close();
}
