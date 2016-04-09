#include <iostream>

#include "Color.h"
#include "Screen.h"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#include "saisies.h"

int
main()
{
  Screen ecran(70,20); // fenêtre terminal : 80 x 25

  // construit le dessin (toutes les formes)

  Line ligne{BLACK, Point{5,1}, Point{60,15} };
  ligne.draw( ecran );


  Rectangle rect{ GREEN, Point{20,3}, Point{50,15} };
  rect.draw( ecran );

  Line ligne2{RED, Point{5,15}, Point{60,1}};
  ligne2.draw( ecran );

  Circle cercle{ BLUE, Point{50,10}, 5 };

  cercle.draw( ecran );

  //  Triangle triangle( Color::BLACK, Point(15,15),
  // Point(25,25), Point(5,40) );
  //  triangle.draw( ecran );

  //  Square carre( Color::BLUE, Point(35,35), 5 );
  //  carre.draw( ecran );

  // affiche le dessin
  ecran.refresh();

  // rajout d'une forme
  // test d'une saisie de forme grâce aux fonctions dans util.*
  Point sw, ne;
  Color col;
  cinRectangle( col, sw, ne );
  Rectangle rect2{col, sw, ne };
  rect2.draw( ecran );

  // affiche le dessin  modifie
  ecran.refresh();

  return 0;
}

