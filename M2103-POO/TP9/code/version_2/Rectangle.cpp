#include "Screen.h"
#include "Point.h"
#include "Rectangle.h"

// pour min et max
#include <algorithm>

using namespace std;

Rectangle::Rectangle( Color col, const Point & a, const Point & b )
  :  Shape{col},
  m_sw{ min(a.getX(), b.getX()),
      min(a.getY(), b.getY())},
  m_ne{ max(a.getX(), b.getX()),
      max(a.getY(), b.getY())}
{
  m_col = col;
}

Rectangle::Rectangle( Color col, const Point & a, int width, int height )
  : Rectangle{col, a,
    Point{a.getX()+width, a.getY()+height} }
{
}

void
Rectangle::move( int dx, int dy )
{
  m_sw.move( dx, dy );
  m_ne.move( dx, dy );
}

void
Rectangle::draw( Screen & s ) const
{
  Color oldPen = s.getColPen();
  s.setColPen( m_col );

  Point nw( m_sw.getX(), m_ne.getY() );
  Point se( m_ne.getX(), m_sw.getY() );

  s.put_line( nw, m_ne );
  s.put_line( m_ne, se );
  s.put_line( se, m_sw );
  s.put_line( m_sw, nw );

  s.setColPen( oldPen );
}
