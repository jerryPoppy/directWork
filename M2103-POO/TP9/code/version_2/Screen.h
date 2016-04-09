#ifndef SCREEN_H
#define SCREEN_H

#include "Point.h"
#include "Color.h"
#include <vector>
#include <map>

class Screen
{

  private:
  // dimensions, tableau de caractères
  int m_xmax, m_ymax;
  std::vector<std::vector<char> > m_screen;

  Color m_colPen;    // Couleur courante
  char m_drawChar;   // caractère de tracé utilisé

  void put_circle_point( int x, int y, const Point & center );
  void put_circle_points( const Point & pt, const Point & center );

 public:

  Screen(int xmax, int ymax);

  void clear();      // efface l'écran (zone) de dessin
  void refresh();    // réaffiche l'écran (zone) de dessin

  // accesseurs pour la couleur du crayon
  void setColPen( Color col );
  Color getColPen() const;

  // fonctions membres pour vérifier des coordonnées
  bool on_screen( const Point & p ) const;
  bool on_screen( int a, int b ) const;

  // primitives de dessin
  void put_point( const Point & p );
  void put_point( int a, int b );

  void put_line( const Point & p1, const Point & p2 );
  void put_line( int x1, int y1, int x2, int y2 );

  void put_circle( const Point & center, int radius );
};

#endif

