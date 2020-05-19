/*
=========================================================
                Klasa macierz pokazujaca,
         ze mnoenie macierzy nie jest przemienne

                    Kamil Wiśniewski
                         Grupa 2
=========================================================
*/
#ifndef MM_H_
#define MM_H_         //ochrona przed wielokrotnym wlaczeniem

class macierz
{
private:
    int kolumna;
    int wiersz;
    double wartosc;
public:
    double tab[2][2];
    macierz();
    ~macierz();
    macierz(int ko,int wi,double wa);
    void set(int kolumna, int wiersz, double wartosc);
    macierz operator=(const macierz & t);
    macierz operator*(const macierz & t) const;
    macierz operator*(double n) const;
    bool operator==(const macierz & t) const;
    friend macierz operator*(double m,const macierz &t);
    void wyp();
    };

#endif // MM_H_
