#include "ImageGenerator.h"
#define hull_window "Drawing: Convex Hull"

ImageGenerator::ImageGenerator(vector<float>& points, vector<float>& hull_points, vector<string>& String_points)
{
    puntos = points;
    hull_puntos = hull_points;
    string_points = String_points;
    hull_image = Mat::zeros( w, w, CV_8UC3 );
}

ImageGenerator::~ImageGenerator()
{
}

void ImageGenerator::MyLine(Point start, Point end)
{
    int thickness = 1;
    int lineType = LINE_8;
    line( hull_image,
    start,
    end,
    Scalar( 0, 255, 0 ),
    thickness,
    lineType ); 
}

void ImageGenerator::MyPoints(vector<float>& puntos)
{
    int radius = 5;
    for(int i=0; i < puntos.size();i=i+2){
        circle(hull_image, 
        Point(puntos[i], w - puntos[i+1]),
        radius,
        Scalar(0,0,0),
        FILLED);
    }   
}

const vector<float> ImageGenerator::NormalizedVector(vector<float>& points) {
    vector<float> normVector(points.size());
    float max = *max_element(points.begin(), points.end());
    float min = *min_element(points.begin(), points.end());
    for (int i = 0; i < points.size(); i++) {
        normVector[i] = (points[i] - min) / (max - min); //normalizamos el vector
        normVector[i] = normVector[i] * 280 + 60;    //lo ajustamos al rango de 60 a 340
    }
    return normVector; 
}

void ImageGenerator::DrawLines(vector<float>& hull_puntos)
{
    for (int i=0; i < hull_puntos.size();i=i+2){
        if (i != hull_puntos.size()-2) {
        MyLine( 
            Point(hull_puntos[i], w - hull_puntos[i+1]), 
            Point(hull_puntos[i+2] , w - hull_puntos[i+3]));
        }
        else
        MyLine(
            Point(hull_puntos[i], w - hull_puntos[i+1]), 
            Point(hull_puntos[0], w - hull_puntos[1]));
        }
}

void ImageGenerator::WritePoints(vector<float>& Normpoints) 
{
    for (int i=0; i < string_points.size();i++){
        putText(hull_image,
            string_points[i],                                       //text
            Point(Normpoints[i*2] - 35, w - 15 - Normpoints[i*2+1]),//Point
            FONT_HERSHEY_PLAIN,                                     //Font
            1,                                                      //Scale    
            Scalar(0,0,0),                                          //Colour
            1,                                                      //Thickness
            LINE_4);                                                //line type            
        }
}

void ImageGenerator::BuildImage()
{
    //fondo blanco
    rectangle(hull_image,
    Point(0,0),
    Point(w,w),
    Scalar(255,255,255),
    FILLED,
    LINE_8);

    normVect = NormalizedVector(puntos);
    normHullVect = NormalizedVector(hull_puntos);
    
    //dibujamos los puntos
    MyPoints(normVect);
    
    //ponemos el texto
    WritePoints(normVect);

    //creamos lineas
    DrawLines(normHullVect);

    //construimos la imagen  
    imshow( hull_window, hull_image );
    moveWindow( hull_window, 0, 200 );
    imwrite("result.png", hull_image);
    waitKey( 0 );
}