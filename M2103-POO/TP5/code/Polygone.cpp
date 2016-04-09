#include <cassert>
#include <iostream>

#include "Polygone.h"

using namespace std;

Polygone::Polygone()
    : m_nb_sommets(0){}

void Polygone::ajouterSommet(Point & un_point) {
    // noter l'adresse de un_point dans m_sommets
    // TODO
}

string Polygone::toString() const {
    string str = "(";
    string sep="";
    // TODO
    return str + ")";
}

