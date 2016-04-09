#ifndef POLYGONE_H
#define POLYGONE_H

#include "Point.h"

#include <iostream>

class Polygone {

private:
    static const int CAPACITE = 10;

    Point * m_sommets [CAPACITE];
    int m_nb_sommets;

public:
    Polygone();

    void ajouterSommet(Point & p);
    std::string toString() const;

};

#endif // POLYGONE_H
