#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

struct sunys
{
    double svoris, gramai, amzius, santykis;
};
//-------------------------------------------------------
void Skaito (int & n, sunys A[], int & a, int & b);
double Santykis (double kg, double maistas);
double Vidurkis (int n, sunys A[], int a, int b);
void Raso (int n, sunys A[], int a, int b);
int main()
{
	int n, a, b;
	sunys A[100];

	Skaito (n, A, a, b);
	Raso(n, A, a, b);


	return 0;
}
void Skaito (int & n, sunys A[], int & a, int & b)
{
    ifstream df ("mityba_duom.txt");


    df >> a >> b;
    df >> n;

    for (int i = 0; i < n; i++)
    {
        df >> A[i].svoris >> A[i].gramai >> A[i].amzius;
        A[i].santykis = Santykis(A[i].svoris, A[i].gramai);
        cout << A[i].santykis << endl;
    }

    df.close();
}
double Santykis (double kg, double maistas)
{
    return maistas/(sqrt(kg*1000));
}
double Vidurkis (int n, sunys A[], int a, int b)
{
    double sum = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i].amzius >= a && A[i].amzius <= b)
        {
            sum += A[i].santykis;
            k++;
        }
    }

    return sum/k;
}
void Raso (int n, sunys A[], int a, int b)
{
    ofstream rf ("mityba_res.txt");

    rf << Vidurkis(n, A, a, b);

    rf.close();
}
