#include "Path.h"


Path::Path(){};

Path::Path(std::vector<Point>& hull_points, int num_segs)
{
    //ctor
    // seed the list of points on creation
    define_path(hull_points, num_segs);
}

Path::~Path()
{
    //dtor
}

void Path::define_path(std::vector<Point>& hull_points, int num_segs)
{
    points.clear();
    float step_size = 1.0/num_segs;
    for( int i = 0; i <= num_segs; i++)
    {
        points.push_back(bezier_point(step_size * i, hull_points));
    }
}

Point Path::midpoint(const Point& a, const Point& b, float dec_percent)
{
    // returns a Point at a given distance along vector AB
    return Point(a.x + (b.x - a.x) * dec_percent,
                 a.y + (b.y - a.y) * dec_percent);
}

Point Path::bezier_point(float percent, const std::vector<Point>& vec)
{
    std::vector<Point> copy = vec;
    while(true)
    {

        //make list Points into midpoints
        int jumps = copy.size() - 1;
        for(int i = 0; i < jumps; ++i)
        {
            copy.push_back(midpoint(copy[0], copy[1], percent));
            copy.erase(copy.begin());
        }
        // erase last of original Point (survives loop above^)
        copy.erase(copy.begin());

        if(jumps-- == 1)
            return copy[0];
    }
}
