#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>
#include <numeric>
using std::vector;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
                                           CGAL::Pointer_property_map<Point_2>::type>
    Convex_hull_traits_2;
class ConvexHull
{
private:
    /* data */
public:
    ConvexHull(/* args */);
    ~ConvexHull();
    int CalculateConvexHull(vector<float>& inputPoints);
    void pointVectorConstructor(vector<float>& inputPoints, vector<Point_2>& out);
    void convertStringToVectorFloat(std::stringstream& in, vector<float>& result);
};


