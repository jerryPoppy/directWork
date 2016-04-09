#ifndef CIRCLE_H
#define CIRCLE_H

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
  protected:
    Point m_center;
    int m_radius;

  public:
    Circle( Color col, const Point & a, int r );
    virtual void move( int dx, int dy );
    virtual void draw( Screen & s ) const;
};

#endif
