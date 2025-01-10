#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>
using namespace std;
struct slap
{
    int ilg,did,maz,spec,skai,sum;
    string stip;
    string slap;
};
void skaitymas(int &n,int &m,slap A[],slap B[]);
void tikrinimas(int &n,int &m,slap A[],slap B[]);
void isvedimas(int &n,int &m,slap A[],slap B[]);
int main()
{
    int n,m;
    slap A[6];
    slap B[25];
    skaitymas(n,m,A,B);
    tikrinimas(n,m,A,B);
    isvedimas(n,m,A,B);
    return 0;
}
void skaitymas(int &n,int &m,slap A[],slap B[])
{
    ifstream in ("Duomenys.txt");
    char eil[16];
    in>>n>>m;
    in.ignore(80, '\n');
    for(int j=0; j<n; j++)
    {
        in.get(eil, 16);
        A[j].slap=eil;
        in>>A[j].ilg>>A[j].did>>A[j].maz>>A[j].skai>>A[j].spec;
        in.ignore(80, '\n');
    }
    for(int i=0; i<m; i++)
    {
        in.get(eil, 16);
        B[i].slap=eil;

        in>>ws;
        in>>B[i].ilg>>B[i].did>>B[i].maz>>B[i].skai>>B[i].spec;
        in>>B[i].stip;
        in.ignore(88, '\n');

    }
}
void tikrinimas(int &n,int &m,slap A[],slap B[])
{ 
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<m; i++)
        {
            B[i].sum = abs(A[j].ilg - B[i].ilg) + abs(A[j].did - B[i].did) + abs(A[j].maz - B[i].maz) + abs(A[j].skai - B[i].skai) + abs(A[j].spec - B[i].spec);
           // cout<<B[i].sum<<endl;

        }
    }



}
void isvedimas(int &n,int &m,slap A[],slap B[])
{

    ofstream out("Rezultatas.txt");

    for(int j=0; j<n; j++)
    {
        out<<A[j].slap<<endl;
int maz;
        for(int i=0; i<m; i++)
        {
          if (maz<B[i].sum)
            {
                maz=B[i].sum;
                cout<<maz<<endl;
               if(maz=B[i].sum)
        {
            cout<<"sane"<<endl;
        }
            } 
        }
        
            
           
    }
}
