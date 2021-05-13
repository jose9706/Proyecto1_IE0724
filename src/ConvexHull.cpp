#include "ConvexHull.h"

ConvexHull::ConvexHull()
{
}
ConvexHull::~ConvexHull()
{
}
/*
* Funcion construye el vector necesario para CGAL a partir de sus entradas.
* @param inputPoints referencia al vector de entrada.
* @param out referencia al vector de salida 
*/
void ConvexHull::pointVectorConstructor(vector<float>& inputPoints, vector<Point_2>& out)
{
    for (auto i = 0; i < inputPoints.size(); i = i + 2)
    {
        out.push_back(Point_2(inputPoints[i], inputPoints[i+1]));
    }
}
/*
* Funcion convierte un stringstream a un vector de floats, esto por la forma que 
* CGAL genera los puntos de salida.
* @param in referencia de puntos de entrada
* @param result vector de salida donde se guardan los puntos ya convertidos
*/
void ConvexHull::convertStringToVectorFloat(std::stringstream& in, vector<float>& result) {
    vector<string> temp = split(in.str(), ' ');
    for (auto i = 0; i < temp.size(); i++) {
        result.push_back(std::stof(temp[i]));
    }
}

/*
* Funcion calcula el ConvexHull de los puntos de entrada y los retorna por medio de otro vector.
* @param inputPoints vector con los puntos de entrada
* @param outputPoints vector con los puntos que construyen el convexHull
*/
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
