#include "Coord.h"
#include <assert.h>

Coord::Coord () : Coord(0,0){}

Coord::Coord(int x, int y) : m_x{x}, m_y{y}
{}

