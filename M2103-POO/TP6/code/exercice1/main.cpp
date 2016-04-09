#include <iostream>
#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"

using namespace std;

int main()
{
    Graphe g;
    Sommet n = g.ajouterSommet();
    Sommet n2 = g.ajouterSommet();
    Sommet n3 = g.ajouterSommet();

    Arete e = g.ajouterArete(n, n2);
    Arete e2 = g.ajouterArete(n2, n3);
    Arete e3 = g.ajouterArete(n3, n);
    cout << g.degre(n) << " / " << g.degre(n2) <<
            " / " << g.degre(n3) << endl;

    g.supprimerArete(e);
    cout << g.degre(n) << " / " << g.degre(n2) <<
            " / " << g.degre(n3) << endl;

    g.supprimerArete(e2);
    cout << g.degre(n) << " / " << g.degre(n2) <<
            " / " << g.degre(n3) << endl;

    g.supprimerArete(e3);
    cout << g.degre(n) << " / " << g.degre(n2) <<
            " / " << g.degre(n3) << endl;
    return 0;
}

