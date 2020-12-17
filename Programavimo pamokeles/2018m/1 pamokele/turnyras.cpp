#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
struct taskai
{
    string komanda;
    int t1, t2;
};

void Skaito (int & n, taskai A[]);
int Viso (int n, taskai A[]);
double Vidurkis (int n, taskai A[]);
void Raso (int n, taskai A[]);
int main()
{
	int n;
	taskai A[100];

	Skaito(n, A);
	Raso(n, A);

	return 0;
}
void Skaito (int & n, taskai A[])
{
    ifstream df ("turnyras.txt");

    df >> n;

    for (int i = 0; i < n; i++) df >> A[i].komanda >> A[i].t1 >> A[i].t2;

    df.close();
}
int Viso (int n, taskai A[])
{
    int sum = 0;

    for (int i = 0; i < n; i++) sum += A[i].t1;

    return sum;
}
double Vidurkis (int n, taskai A[])
{
    double sum = 0;

    for (int i = 0; i < n; i++) sum += A[i].t1;

    return sum/n;
}
void Raso (int n, taskai A[])
{
    ofstream rf ("turnyras_rez.txt");

    rf << Viso(n, A) << endl << fixed << setprecision(2) << Vidurkis(n, A);

    rf.close();
}
