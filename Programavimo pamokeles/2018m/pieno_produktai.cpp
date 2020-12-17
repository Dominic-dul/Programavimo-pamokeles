#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------
struct produktai
{
    string pav;
    int laikas;
};
void Skaito (int & n, int & t1, int & t2, produktai A[]);
void Raso (int n, int t1, int t2, produktai A[]);
int main()
{
    int n, t1, t2;
    produktai A[100];

    Skaito (n, t1, t2, A);
    Raso (n, t1, t2, A);

	return 0;
}
void Skaito (int & n, int & t1, int & t2, produktai A[])
{
    int met1, men1, d1, met2, men2, d2, met, men, d, k;
    ifstream df ("produktai.txt");

    df >> n;
    df >> met1 >> men1 >> d1 >> met2 >> men2 >> d2;

    if (men1 == 2) t1 == met1*12 + men1*28 + d1;
    else if (men1 == 4 || men1 == 6 || men1 == 9 || men1 == 11) t1 = met1*12 + men1*30 + d1;
    else t1 = met1*12 + men1*31 + d1;

    if (men2 == 2) t2 == met2*12 + men2*28 + d2;
    else if (men2 == 4 || men2 == 6 || men2 == 9 || men2 == 11) t2 = met2*12 + men2*30 + d2;
    else t2 = met2*12 + men2*31 + d2;

    for (int i = 0; i < n; i++)
    {
        df.ignore();
        df >> A[i].pav >> met >> men >> d >> k;
        if (men == 2) A[i].laikas == met*12 + men*28 + d + k;
        else if (men == 4 || men == 6 || men == 9 || men == 11) A[i].laikas = met*12 + men*30 + d+k;
        else A[i].laikas = met*12 + men*31 + d+k;
    }

    df.close();
}
void Raso (int n, int t1, int t2, produktai A[])
{
    ofstream rf ("produktai_res.txt");

    rf << "PIRMAS SARASAS: " << endl;

    for (int i = 0; i < n; i++)
    {
        if (A[i].laikas >= t1 && A[i].laikas <= t2 || A[i].laikas < t1) rf << A[i].pav << endl;
    }

    rf << "ANTRAS SARASAS: " << endl;

    for (int i = 0; i < n; i++)
    {
        if (A[i].laikas > t2) rf << A[i].pav << endl;
    }

    rf.close();
}
