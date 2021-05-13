#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>
#include <numeric>
#include "FileManager.h"
using std::vector;
using std::string;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
                                           CGAL::Pointer_property_map<Point_2>::type>
    Convex_hull_traits_2;

/*
Clase genera los puntos del ConvexHull por medio de varias funciones, solo utiliza referencias. 
Para el calculo del ConvexHull utiliza CGAL. Para efectos de debug se hereda la funcion de 
impresio nde vectores de FileManager
*/
class ConvexHull : FileManager
{
public:
    ConvexHull();
    ~ConvexHull();
    void CalculateConvexHull(vector<float>& inputPoints, vector<float>& outputPoints);
    void pointVectorConstructor(vector<float>& inputPoints, vector<Point_2>& out);
    void convertStringToVectorFloat(std::stringstream& in, vector<float>& result);
};


