#ifndef POINT_HPP
#define POINT_HPP
/**
 * @brief Point on a plane with floats as coordinates
 *
 */
class Point
{
    float x, y;

public:
    Point(float abscissa, float ordinate);
    void move(float move_x, float move_y);
    float abscissa() const;
    float ordinate() const;
};

#endif