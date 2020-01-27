#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Instrument {
    public:
        Instrument( const char* n ) : name{n} { } 
        // dopisz reszte

    private:
        const string name;
};

// dopisz klasy Skrzypce i Fortepian, publicznie dziedziczące z Instrument

class Struna {
    public:
        double dlugosc( double d = 0.0 ); // zdefiniuj
    private:
        double len { 0. };
}; 


int main() {
   Instrument *p1 = new Skrzypce("Stradivari");
   Instrument *p2 = new Fortepian("Steinway");
   dynamic_cast<Fortepian*>(p2)->klawisze(88);
   cout << "Instrument " << p1->nazwa() << " gra " << p1->graj() << endl;
   cout << "Instrument " << p2->nazwa() << " gra " << p2->graj() << endl;
   Fortepian* pf = dynamic_cast<Fortepian*>(p2);
   cout << "Fortepian ma " << pf->klawisze() << " klawiszy" << endl;
   Skrzypce* ps = dynamic_cast<Skrzypce*>(p1);
   ps->struna(Struna(60.)); // dodaje strune
   ps->struna(Struna(62.)); // dodaje kolejna strune
   cout << "Skrzypce maja " << ps->struny() << " struny" << endl;
   cout << "Struna 1 ma dlugosc " << ps->struna(1)->dlugosc() << endl;
   ps->struna(1)->dlugosc(70.); // zmiana dlugosci
   cout << "Struna 1 ma teraz dlugosc " << ps->struna(1)->dlugosc() << endl;
   delete p1;
   delete p2;
}