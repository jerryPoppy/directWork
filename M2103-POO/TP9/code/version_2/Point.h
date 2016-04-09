// Fichier Point.h

#ifndef POINT_H
#define POINT_H

#include <sstream>
#include <string>

class Point {
  private :
    int m_abs, m_ord;
  public :
    Point( int x, int y );                     // constructeur
    Point();
                                 // constructeur par defaut
    std::string toString() const;
    int getX() const;
    int getY() const;
    void setX( int new_x );
    void setY( int new_y );

    void move( int d_x, int d_y );
};

std::ostream& operator<<(std::ostream& out, const Point& p);
#endif

