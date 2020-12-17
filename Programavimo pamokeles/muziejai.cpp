#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;
struct muziejai
{
    string pav;
    int l;
};
//-------------------------------------------------------
void Skaito (int & n, string & miestas, muziejai A[]);
void Rikiuoti (int n, muziejai A[]);
void Raso (int n, string miestas, muziejai A[]);
int main()
{
    int n;
    string miestas;
    muziejai A[100];

    Skaito (n, miestas, A);
    Rikiuoti (n, A);
    Raso (n, miestas, A);

	return 0;
}
void Skaito (int & n, string & miestas, muziejai A[])
{
    ifstream df ("muziejai.txt");

    df >> n >> miestas;

    for (int i = 0; i < n; i++) df >> A[i].pav >> A[i].l;

    df.close();
}
void Rikiuoti (int n, muziejai A[])
{
    muziejai t;
    int m;

    for (int i = 0; i < n-1; i++)
    {
        m = i;
        for (int j = i+1; j < n; j++)
            if (A[j].l > A[m].l) m = j;
        t = A[i]; A[i] = A[m]; A[m]=t;
    }
}
void Raso (int n, string miestas, muziejai A[])
{
    ofstream rf ("muziejai_res.txt");

    rf << "Lankomiausi " << miestas << " muziejai: " << endl;

    for (int i = 0; i < 3; i++) rf << A[i].pav << endl;

    rf.close();
}
