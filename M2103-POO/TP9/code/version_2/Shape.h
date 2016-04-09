#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "Screen.h"

class Shape
{
  protected:
    Color m_col;

  public:
    Shape (Color col);
    virtual ~Shape();
    virtual void draw( Screen & s ) const  = 0;
    virtual void move( int dx, int dy ) = 0;

    void setColour( Color col );
    Color getColour( ) const;
};

#endif

