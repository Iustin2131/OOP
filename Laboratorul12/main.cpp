#include <iostream>
#include <vector>
#include "head.h"
using namespace std;

int main()
{
    Agenda agenda;

    agenda.adaugaContact(new Prieten("Larisa Apetrei", "18/08/2004", "+40 666287562", "Mihai Viteazul 32"));
    agenda.adaugaContact(new Prieten("Tiganescu Iustin", "05/11/2000", "+40 620287461", "George Enescu 65"));
    agenda.adaugaContact(new Prieten("Cazacu Ion", "25/08/2003", "+40 626392661", "Stefan cel Mare 192"));
    agenda.adaugaContact(new Cunoscut("Gaina Diana", "+373 781324530"));
    agenda.adaugaContact(new Coleg("Mocanu George", "+40 627654890", "Oriflame", "Strada Lucrãtorilor 2"));

    Contact* contact = agenda.cautaContact("Tiganescu Iustin");
    if (contact)
    {
        cout << "Contactul \"" << contact->getNume() << "\" a fost gasit." << endl;
    }
    else
    {
        cout << "Contactul nu a fost gasit." << endl;
    }

    agenda.stergeContact("Sturza Dumitru");

    vector<Prieten*> prieteni = agenda.getPrieteni();
    cout << "Lista de prieteni:" << endl;
    for (auto prieten : prieteni)
    {
        cout << "  - " << prieten->getNume() << endl;
    }

    return 0;
}
