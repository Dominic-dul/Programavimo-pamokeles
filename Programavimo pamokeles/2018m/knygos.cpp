#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
void Skaito (int & k, int & s, int Knygos[], int Skirtukai[]);
void Truksta (int k, int s, int Knygos[], int Skirtukai[], int A[], int B[], int Tk[], int Ts[]);
int main()
{
	int k, s, Knygos[100], Skirtukai[100], A[100], B[100], Tk[100], Ts[100];

	Skaito (k, s, Knygos, Skirtukai);
	Truksta(k, s, Knygos, Skirtukai, A, B, Tk, Ts);

	cout << "Truksta knygu: " << endl;
	for (int i = 1; i <=100; i++)
	{
	    if (Tk[i] > 0) cout << i << " " << Tk[i] << endl;
	}
	cout << "Truksta skirtuku: " << endl;
	for (int i = 1; i <=100; i++)
    {
        if (Ts[i] > 0) cout << i << " " << Ts[i] << endl;
    }

	return 0;
}
void Skaito (int & k, int & s, int Knygos[], int Skirtukai[])
{
    ifstream df ("knygos.txt");

    df >> k >> s;

    for (int i = 1; i <= k; i++) df >> Knygos[i];
    for (int i = 1; i <= s; i++) df >> Skirtukai[i];

    df.close();
}
void Truksta (int k, int s, int Knygos[], int Skirtukai[], int A[], int B[], int Tk[], int Ts[])
{
    for (int i = 1; i <=100; i++) A[i] = 0, B[i] = 0;


    for (int i = 1; i <= k; i++)
        A[Knygos[i]]++;
    for (int i = 1; i <= s; i++)
    {
        B[Skirtukai[i]]++;
    }


    for (int i = 1; i <=100; i++) Tk[i] = B[i]-A[i];

    for (int i = 1; i <=100; i++) Ts[i] = A[i]-B[i];

}
