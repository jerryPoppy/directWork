#include <iostream>

#include "Point.h"

using namespace std;

Point::Point(int x, int y) {
    m_x = x;
    m_y = y;
}

void Point::deplacer(int dx, int dy) {
    m_x += dx;
    m_y += dy;
}

string Point::toString() const {
    return "(" + to_string(m_x) + ","
           + to_string(m_y) +")";
}
