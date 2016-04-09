#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape
{
  private:
    void search_sw_ne( const Point & a, const Point & b );

  protected:
    Point m_sw, m_ne;

  public:
    Rectangle( Color col, const Point & a, const Point & b );
    Rectangle( Color col, const Point & a, int width, int height );

    virtual void move( int dx, int dy );
    virtual void draw( Screen & s ) const;
};

#endif
