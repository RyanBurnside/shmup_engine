#ifndef PATH_H
#define PATH_H

#include <vector>

struct Point
{
    Point(float new_x, float new_y) : x(new_x), y(new_y){}
    float x, y;
};

class Path
{
    // a collection of points along a Bezier curve
    public:
        Path();
        Path(std::vector<Point>& hull_points, int num_segs);
        virtual ~Path();
        void define_path(std::vector<Point>& hull_points, int num_segs);
        std::vector<Point> points;
    protected:
        Point midpoint(const Point& a, const Point& b, float dec_percent);
        Point bezier_point(float percent, const std::vector<Point>& vec);
    private:
};

#endif // PATH_H
