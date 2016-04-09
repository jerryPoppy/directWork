#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include "Graphe.h"
#include "Coord.h"

enum MODE{AJOUT, AJOUT_COMMENCE, SUPPRESSION};

class Appli
{
public:
    Appli();
    void run();
    void setGraphe(Graphe &g);

private:

    sf::RenderWindow   m_fenetre;
    sf::CircleShape    m_sommet;
    Graphe * m_g;

    // ajout interaction
    MODE m_mode;
    Coord m_coord_debut, m_coord_fin;

    void traiter_evenements();
    void dessiner();

    static const float RAYON;
};

#endif // APPLI_H
