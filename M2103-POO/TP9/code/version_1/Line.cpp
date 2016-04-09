#include "Screen.h"
#include "Point.h"
#include "Line.h"


Line::Line( Color col, const Point & a, const Point & b )
  : Shape{ col },
  m_w { a },
  m_e { b }
{}

Line::Line( Color col, const Point & a, int l )
  : Line{col, a,  Point( a.getX()+l-1, a.getY())}
{}

Line::~Line()
{}

void
Line::move( int dx, int dy )
{
  m_w.move( dx, dy );
  m_e.move( dx, dy );
}

void
Line::draw( Screen & s ) const
{
  Color oldPen = s.getColPen();
  s.setColPen( m_col );

  s.put_line( m_w, m_e );

  s.setColPen( oldPen );
}
