#include <set>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Appli.h"
#include "Coord.h"
using namespace std;
using namespace sf;


/*
 constantes et fonction auxiliaires
 pour l'implémentation de Appli
*/

const float Appli::RAYON          = 10.0;

// ---------------------------------------

Appli::Appli()
    : m_fenetre {sf::VideoMode {800, 600, 32},
                 "Exemple 2",
                 sf::Style::Close
                 }
    , m_sommet(RAYON), m_mode(AJOUT)

{
    m_fenetre.setFramerateLimit(50);
    m_sommet.setOrigin({RAYON, RAYON});
    m_sommet.setFillColor(sf::Color::Red);
    m_sommet.setOutlineColor(sf::Color::Black);
    m_sommet.setOutlineThickness(1.);
}

// ---------------------------------------

void Appli::run()
{
    while (m_fenetre.isOpen())
    {
        traiter_evenements();
        dessiner();
    }
}

// ---------------------------------------
void Appli::setGraphe(Graphe &g){
    m_g = &g;
}

// ---------------------------------------

void Appli::traiter_evenements()
{
    sf::Event evenement;
    while (m_fenetre.pollEvent(evenement)) {
        switch (evenement.type) {
        case sf::Event::Closed : // gestionnaire de fenêtre
            m_fenetre.close();
            break;
        case  sf::Event::KeyPressed : // clavier
            switch (evenement.key.code) {
            case  sf::Keyboard::Escape :  // touche échappement
                m_fenetre.close();
                break;
            default:
                // autre touche
                break;

            };
	    break;
        default:
            // autre événement
            break;
        }
    }
}

// ---------------------------------------

void Appli::dessiner()
{
    m_fenetre.clear(sf::Color::White);

    //dessin des aretes
    for(auto e : m_g->aretes()){
        Sommet src = m_g->source(e);
        Sommet dest = m_g->destination(e);

        Coord c_src = m_g->positionSommet(src);
        Coord c_dest = m_g->positionSommet(dest);
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(c_src.m_x, c_src.m_y), sf::Color::Black),
            sf::Vertex(sf::Vector2f(c_dest.m_x, c_dest.m_y), sf::Color::Black)
        };
        m_fenetre.draw(line, 2, sf::Lines);
    }

    // dessin des sommets
    for(auto n : m_g->sommets()){
        Coord c = m_g->positionSommet(n);
        sf::Vector2f pos {c.m_x, c.m_y};
        m_sommet.setPosition(pos);
        m_fenetre.draw(m_sommet);
    }

    m_fenetre.display();

}
