#ifndef LINE_H
#define LINE_H

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Line : public Shape
{
  protected:
    Point m_w, m_e;

  public:
    Line( Color col, const Point & a, const Point & b );
    Line( Color, const Point & a, int l );
    virtual ~Line();
    virtual void move( int dx, int dy ) override;
    virtual void draw( Screen & s ) const override;
};

#endif

