#ifndef SAISIES_H
#define SAISIES_H

#include "Point.h"
#include "Color.h"

void cinColour( Color & col );
void cinPoint( Point & a );

void cinLine( Color & col, Point & sw, Point & ne );
void cinLineHoriz( Color & col, Point & sw, int & w );

void cinRectangle( Color & col, Point & sw, Point & ne );

void cinCircle( Color & col, Point & c, int & r );

#endif

