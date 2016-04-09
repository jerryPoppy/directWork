#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    int m_x, m_y;

public:
    Point(int x, int y);
    void deplacer(int dx, int dy);
    std::string toString() const;

};

#endif // POINT_H
