#include <iostream>

#include "Point.h"
#include "Polygone.h"

using namespace std;

void test_ajout() {
    cout << "* début " << __FUNCTION__ << endl;

    Point a(0,0), b(30,0), c(0,50);
    Polygone triangle;

    triangle.ajouterSommet(a);
    triangle.ajouterSommet(b);
    triangle.ajouterSommet(c);

    cout << "Le triangle avant : "
         << triangle.toString()
         << endl;

    a.deplacer(100,100);

    cout << "Le triangle après : "
         << triangle.toString()
         << endl;

    cout << "* fin " << __FUNCTION__ << endl << endl;
}


void test_copie() {
    cout << "* début " << __FUNCTION__ << endl;

    Point a(0,0);
    Polygone p1;

    p1.ajouterSommet(a);

    Polygone p2 {p1};  // p2 = copie de p1

    cout << "- après copie :" << endl
         << "    p1 = " << p1.toString() << endl
         << "    p2 = " << p2.toString() << endl;

    Point b(10,0);
    p1.ajouterSommet(b);
    Point c(0,30);
    p2.ajouterSommet(c);

    cout << "- après ajouts :" << endl
         << "    p1 = " << p1.toString() << endl
         << "    p2 = " << p2.toString() << endl;


    cout << "* fin " << __FUNCTION__ << endl << endl;
}

void test_affectation() {
    cout << "* début " << __FUNCTION__ << endl;

    Point a(0,0);
    Polygone p1;

    p1.ajouterSommet(a);

    Polygone p2;
    p2 = p1;  // affectation

    cout << "- après copie :" << endl
         << "    p1 = " << p1.toString() << endl
         << "    p2 = " << p2.toString() << endl;

    Point b(10,0);
    p1.ajouterSommet(b);
    Point c(0,30);
    p2.ajouterSommet(c);

    cout << "- après ajouts :" << endl
         << "    p1 = " << p1.toString() << endl
         << "    p2 = " << p2.toString() << endl;

    cout << "* fin " << __FUNCTION__ << endl << endl;
}


int main() {
    test_ajout();
    test_copie();
    test_affectation();

    return 0;
}
