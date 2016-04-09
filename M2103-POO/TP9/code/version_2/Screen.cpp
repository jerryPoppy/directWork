#include <iostream>
#include "Screen.h"
#include "Point.h"
#include <vector>

using namespace std;

Screen::Screen(int xmax, int ymax) :
  m_xmax{xmax},
  m_ymax{ymax},
  m_screen{ xmax , vector<char>(ymax)}
{
  setColPen(Color::WHITE);
  clear();
}

void
Screen::clear()
{
  for (int y=0; y<m_ymax; y++)
    for (int x=0; x<m_xmax; x++)
      m_screen[x][y] = ' ';

  // axes
  m_screen[0][0] = '0';
  for (int x=1; x<m_xmax; x++)
    m_screen[x][0] = 'x';
  for (int y=1; y<m_ymax; y++)
    m_screen[0][y] = 'y';
}

void
Screen::refresh()
{
  for (int y=m_ymax-1; 0<=y; y--)
  {
    for (int x=0; x<m_xmax; x++)
      cout << m_screen[x][y];
    cout << endl;
  }
}

void
Screen::setColPen( Color col )
{
  m_colPen = col;
  m_drawChar =
    col == Color::WHITE ? ' ' :
    col == Color::BLACK ? '*' :
    col == Color::RED ? '+' :
    col == Color::BLUE ? '#' :
    col == Color::GREEN ? '%' :
    '?';
}

Color
Screen::getColPen() const
{
  return m_colPen;
}

bool
Screen::on_screen( const Point & p ) const
{
  return on_screen( p.getX(), p.getY() );
}

bool
Screen::on_screen( int a, int b ) const
{
  return 0<=a && a<m_xmax && 0<=b && b<m_ymax;
}

void
Screen::put_point( const Point & p )
{
  put_point( p.getX(), p.getY() );
}

void
Screen::put_point( int a, int b )
{
  if( on_screen(a,b) )
    m_screen[a][b] = m_drawChar;
}

void
Screen::put_line( const Point & p1, const Point & p2 )
{
  put_line( p1.getX(), p1.getY(), p2.getX(), p2.getY() );
}

void
Screen::put_line ( int x1, int y1, int x2, int y2 )
{
  int dx = 1;
  int dy = 1;
  int eps = 0;

  int  a = x2 - x1;
  int  b = y2 - y1;
  int  two_a;
  int  two_b;
  int  xcrit;

  if (a < 0) { dx = -1; a = -a; }
  if (b < 0) { dy = -1; b = -b; }

  two_a = 2 * a;
  two_b = 2 * b;
  xcrit = -b + two_a;

  put_point( x1, y1 );
  while( x1 != x2 || y1 != y2 )
  {
    if (eps <= xcrit)       { x1 += dx;  eps += two_b; }
	if (eps >= a || a <= b) { y1 += dy;  eps -= two_a; }
	put_point( x1, y1 );
  }
}

// draw a point, offset by the location
// of the center of the circle
void
Screen::put_circle_point( int x, int y, const Point & center )
{
  put_point( x + center.getX(), y + center.getY() );
}
// draw the point in all 8 octants
void
Screen::put_circle_points( const Point & pt, const Point & center )
{
  put_circle_point( pt.getX(),  pt.getY(), center );
  put_circle_point( pt.getY(),  pt.getX(), center );
  put_circle_point( pt.getY(), -pt.getX(), center );
  put_circle_point( pt.getX(), -pt.getY(), center );
  put_circle_point( -pt.getX(), -pt.getY(), center );
  put_circle_point( -pt.getY(), -pt.getX(), center );
  put_circle_point( -pt.getY(),  pt.getX(), center );
  put_circle_point( -pt.getX(),  pt.getY(), center );
}
// draw a circle using Bresenham's algorithm
// as described by Foley and Van Dam, 1982
void
Screen::put_circle( const Point & center, int radius )
{
  Point pt(0, radius);
  int d = 3 - 2 * radius;

  while( pt.getX() < pt.getY() )
  {
    put_circle_points( pt, center );
    if (d < 0)
	  d += 4 * pt.getX() + 6;
    else
	{
	  d += 4 * (pt.getX() - pt.getY()) + 10;
	  pt.setY( pt.getY()-1 );
	}
    pt.setX( pt.getX()+1 );
  }
  if( pt.getX() == pt.getY() )
    put_circle_points( pt, center );
}
