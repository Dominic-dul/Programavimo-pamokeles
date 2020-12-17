#include <iomanip>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;
struct dakaras
{
    string v, p;
    int val, min;
    double greitis;
};
//-------------------------------------------------------
void Skaito (int & n, dakaras A[]);
double Greit (int val, int min);
double Vid (int n, dakaras A[]);
double Laikas (int n, dakaras A[]);
void Raso (int n, dakaras A[]);
int main()
{
    int n, val, min;
    dakaras A[100];

    Skaito (n, A);
    Raso(n, A);

	return 0;
}
void Skaito (int & n, dakaras A[])
{
    ifstream df ("dakaras_duom.txt");

    df >> n;

    for (int i = 0; i < n; i++)
    {
        df.ignore();
        df >> A[i].v >> A[i].p >> A[i].val >> A[i].min;
        A[i].greitis = Greit(A[i].val, A[i].min);
    }

    df.close();
}
double Greit (int val, int min)
{
    double va = val, mi = min;
    double d = 760;

    return d / (va + (mi/60));
}
double Vid (int n, dakaras A[])
{
    double x = n;
    double sum = 0;

    for (int i = 0;  i< n; i++) sum += A[i].greitis;

    return sum/x;
}
double Laikas (int n, dakaras A[])
{
    double sum = 0;

    for (int i = 0; i < n; i++) sum += A[i].val * 60 + A[i].min;

    return sum / 60;
}
void Raso (int n, dakaras A[])
{
    ofstream rf ("dakaras_res.txt");

    double vidutinis = Vid(n, A);

    rf << fixed << setprecision(2);

    for (int i = 0; i < n; i++)
        if(A[i].greitis >= vidutinis) rf << A[i].v << " " << A[i].p << " " << A[i].greitis << " km/h" << endl;

    rf << "Bendras laikas: " << Laikas(n, A) << " h" << endl;
    rf << "Greicio vidurkis: " << vidutinis << " km/h" << endl;

    rf.close();
}
