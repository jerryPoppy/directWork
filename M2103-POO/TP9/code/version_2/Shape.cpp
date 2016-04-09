#include "Shape.h"


Shape::Shape(Color col)
  : m_col{col}
{}

Color
Shape::getColour( ) const
{
  return m_col;
}

 Shape::~Shape()
 {}
