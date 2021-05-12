#include "ConvexHull.h"

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

void ConvexHull::CalculateConvexHull(vector<float>& inputPoints, vector<float>& outputPoints)
{
    vector<Point_2> points;
    std::stringstream buffer;
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
    convertStringToVectorFloat(buffer, outputPoints);
    std::cout << "Printing result vector \n";
    printVector(outputPoints);
}
