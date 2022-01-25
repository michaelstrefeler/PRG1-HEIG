#ifndef POINT_HPP
#define POINT_HPP
/**
 * @brief Point on a plane with floats as coordinates
 *
 */
#include <cmath>
const float PI = float(atan2(0.0, -1.0));
class Point
{
    float x, y;
public:
    Point(float abscissa, float ordinate);
    void move(float move_x, float move_y);
    float abscissa() const;
    float ordinate() const;
    float rho() const;
    float theta() const;
    Point operator+(const Point& right) const;
    void rotation(float angle);
};

#endif