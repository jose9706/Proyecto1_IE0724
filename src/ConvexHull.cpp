#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Convex_hull_traits_adapter_2.h>
#include <CGAL/property_map.h>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include "FileManager.h"

using std::vector;
using std::string;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Convex_hull_traits_adapter_2<K,
                                           CGAL::Pointer_property_map<Point_2>::type>
    Convex_hull_traits_2;

class ConvexHull : public FileManager
{
public:
    ConvexHull();
    ~ConvexHull();
    int CalculateConvexHull(vector<float>& inputPoints);
    void pointVectorConstructor(vector<float>& inputPoints, vector<Point_2>& out);
    void convertStringToVectorFloat(std::stringstream& in, vector<float>& result);
};

ConvexHull::ConvexHull()
{
}
ConvexHull::~ConvexHull()
{
}

void ConvexHull::pointVectorConstructor(vector<float>& inputPoints, vector<Point_2>& out)
{
    for (auto i = 0; i < inputPoints.size(); i = i + 2)
    {
        out.push_back(Point_2(inputPoints[i], inputPoints[i+1]));
    }
}

void ConvexHull::convertStringToVectorFloat(std::stringstream& in, vector<float>& result) {
    vector<string> temp = split(in.str(), ' ');
    for (auto i = 0; i < temp.size(); i++) {
        result.push_back(std::stof(temp[i]));
    }
}

int ConvexHull::CalculateConvexHull(vector<float>& inputPoints)
{
    vector<Point_2> points;
    std::stringstream buffer;
    vector<float> HullPoints; 
    pointVectorConstructor(inputPoints, points);
    vector<std::size_t> indices(points.size()), out;
    std::iota(indices.begin(), indices.end(), 0);
    CGAL::convex_hull_2(indices.begin(), indices.end(), std::back_inserter(out),
                        Convex_hull_traits_2(CGAL::make_property_map(points)));
    for (std::size_t i : out)
    {
        //std::cout << "points[" << i << "] = " << points[i] << std::endl;
        buffer << points[i] << " ";
    }
    convertStringToVectorFloat(buffer, HullPoints);
    std::cout << "Printing result vector \n";
    printVector(HullPoints);
    return 0;
}
