#include "macierz.h"

    macierz::macierz()                                              //konstruktor bezargumentow
    {
    kolumna=0;
    wiersz=0;
    wartosc=0;
    }
    macierz::macierz(int ko,int wi,double wa)                       //konstruktor
    {
    kolumna=ko;
    wiersz=wi;
    wartosc=wa;
    }

    macierz::~macierz()                                             //destruktor
    {
        for (int i=0;i<2;i++)
        {
            delete[]tab[i];
        }
    delete[] tab;
    }



    void macierz::set(int kolumna, int wiersz, double wartosc)      //ustawianie wartosci do tablicy
    {
    tab[kolumna][wiersz]=wartosc;
    }

    macierz macierz::operator=(const macierz & t)                   //operator= przypisujacy wartosci z jednej macirzy do drugiej
    {
    this->tab[0][0]=t.tab[0][0];
    this->tab[0][1]=t.tab[0][1];
    this->tab[1][0]=t.tab[1][0];
    this->tab[1][1]=t.tab[1][1];
    return *this;
    }
    macierz macierz::operator*(const macierz & t) const             //operator* pozwalajacy policzyc macierz*macierz
    {
    macierz mno;
    mno.tab[0][0]=tab[0][0]*t.tab[0][0]+tab[0][1]*t.tab[1][0];
    mno.tab[0][1]=tab[0][0]*t.tab[0][1]+tab[0][1]*t.tab[1][1];
    mno.tab[1][0]=tab[1][0]*t.tab[0][0]+tab[1][1]*t.tab[1][0];
    mno.tab[1][1]=tab[1][0]*t.tab[0][1]+tab[1][1]*t.tab[1][1];

    return mno;
    }
    macierz macierz::operator*(double n) const                      //operator* mnozacy macierz*liczba
    {
    macierz skal;
    skal.tab[0][0]=tab[0][0]*n;
    skal.tab[0][1]=tab[0][1]*n;
    skal.tab[1][0]=tab[1][0]*n;
    skal.tab[1][1]=tab[1][1]*n;

    return skal;
}

    bool macierz::operator==(const macierz & t) const               //operator== sprawdzaiajcy czy macierz jedna jest rowna macierzy drugiej
    {
    if(tab[0][0]==t.tab[0][0]&&tab[0][1]==t.tab[0][1]&&tab[1][0]==t.tab[1][0]&&tab[1][1]==t.tab[1][1])
        return true;
    else
        return false;
    }
   macierz operator*(double m,const macierz &t)                     //operator* mnozacy liczba*macierz
    {
    macierz ska;
    ska.tab[0][0]=m*t.tab[0][0];
    ska.tab[0][1]=m*t.tab[0][1];
    ska.tab[1][0]=m*t.tab[1][0];
    ska.tab[1][1]=m*t.tab[1][1];
    return ska;
    }

