#include "Screen.h"
#include "Point.h"
#include "Circle.h"


Circle::Circle( Color col, const Point & a, int r )
  : Shape{col},
  m_center{a},
  m_radius{r}
{
}

void
Circle::move( int dx, int dy )
{
  m_center.move( dx, dy );
}

void
Circle::draw( Screen & s ) const
{
  Color oldPen = s.getColPen();
  s.setColPen( m_col );
  s.put_circle( m_center, m_radius );
  s.setColPen( oldPen );
}
