#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "Appli.h"
using namespace std;
using namespace sf;

int main()
{
    Graphe g;
    Sommet n = g.ajouterSommet();
    Sommet n2 = g.ajouterSommet();
    Sommet n3 = g.ajouterSommet();

    g.positionSommet(n, Coord(100,100));
    g.positionSommet(n2, Coord(200,200));
    g.positionSommet(n3, Coord(400,100));

    Arete e = g.ajouterArete(n, n2);
    Arete e2 = g.ajouterArete(n2, n3);
    Arete e3 = g.ajouterArete(n3, n);

    cout << g.degre(n) << " / " << g.degre(n2) <<
               " / " << g.degre(n3) << endl;

    Appli app;
    app.setGraphe(g);
    app.run();

    return 0;
}

