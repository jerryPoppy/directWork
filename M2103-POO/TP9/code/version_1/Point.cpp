// Fichier Point.cc
#include <string>

#include "Point.h"

using namespace std;

ostream& operator<<(ostream& out, const Point& p) {
  out << p.toString();
  return out;
}

Point::Point( int x, int y ) : m_abs{x}, m_ord{y} {}

Point::Point() : m_abs{0}, m_ord{0} {}


string
Point::toString() const
{
  return "(" + to_string( m_abs)
    + "," +  to_string(m_ord)
    + ")";
}

int
Point::getX() const {
  return m_abs;
}

int
Point::getY() const {
  return m_ord;
}

void
Point::setX( int new_x ) {
  m_abs = new_x;
}

void
Point::setY( int new_y ) {
  m_ord = new_y;
}

void
Point::move( int d_x, int d_y ) {
  m_abs += d_x;
  m_ord += d_y;
}

