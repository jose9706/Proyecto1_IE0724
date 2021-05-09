#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <algorithm>
#include <functional>
#define w 400
using namespace cv;
using std::vector;
using std::string;

void MyLine( Mat img, Point start, Point end );
void MyPoints(Mat img, vector<float>& puntos);
const vector<float> NormalizedVector(vector<float>& puntos);
void DrawLines(Mat img, vector<float>& puntos);
void WritePoints(Mat img, vector<string>& string_points, vector<float>& Normpoints);

int main (void){
    char hull_window[] = "Drawing: Convex Hull";
    Mat hull_image = Mat::zeros( w, w, CV_8UC3 );
    
    //fondo blanco
    rectangle(hull_image,
            Point(0,0),
            Point(w,w),
            Scalar(255,255,255),
            FILLED,
            LINE_8);

    //puntos de entrada
    //vector <float> puntos{0, 0, 10, 0, 10, 10, 0, 10};
    vector <float> puntos{-40, 70, 80, -50, -80, -65};
    vector <string> string_points{"-40, 70", "80, -50", "-80, -65"};

    //normalizamos los puntos y luego los escalamos al tamano de ventana
    vector <float> normVect = NormalizedVector(puntos);
    
    //dibujamos los puntos
    MyPoints(hull_image, normVect);

    //ponemos el texto
    WritePoints(hull_image, string_points, normVect);
    
    //creamos lineas
    DrawLines(hull_image, normVect);

    //construimos la imagen  
    imshow( hull_window, hull_image );
    moveWindow( hull_window, 0, 200 );
    imwrite("result.png", hull_image);
    waitKey( 0 );
    return(0);
}

//funcion para lineas
void MyLine( Mat img, Point start, Point end )
{
  int thickness = 1;
  int lineType = LINE_8;
  line( img,
    start,
    end,
    Scalar( 0, 255, 0 ),
    thickness,
    lineType );
}

void MyPoints(Mat img, vector<float>& puntos)
{
  int radius = 5;
  for(int i=0; i < puntos.size();i=i+2){
    circle(img, 
      Point(puntos[i], w - puntos[i+1]),
      radius,
      Scalar(0,0,0),
      FILLED);
  }
}

const vector<float> NormalizedVector(vector<float>& puntos)
{
  vector<float> normVector(puntos.size());
  float max = *max_element(puntos.begin(), puntos.end());
  float min = *min_element(puntos.begin(), puntos.end());
  for (int i = 0; i < puntos.size(); i++) {
    normVector[i] = (puntos[i] - min) / (max - min); //normalizamos el vector
    normVector[i] = normVector[i] * 280 + 60;    //lo ajustamos al rango de 60 a 340
  }
  return normVector;   
}

void DrawLines(Mat img, vector<float>& puntos)
{
  for (int i=0; i < puntos.size();i=i+2){
    if (i != puntos.size()-2) {
      MyLine(img, 
        Point(puntos[i], w - puntos[i+1]), 
        Point(puntos[i+2] , w - puntos[i+3]));
    }
    else
      MyLine(img, 
        Point(puntos[i], w - puntos[i+1]), 
        Point(puntos[0], w - puntos[1]));
    }
}

void WritePoints (Mat img, vector<string>& string_points, vector<float>& Normpoints)
{
  for (int i=0; i < string_points.size();i++){
    putText(img,
          string_points[i],                                       //text
          Point(Normpoints[i*2] - 35, w -15 - Normpoints[i*2+1]), //Point
          FONT_HERSHEY_PLAIN,                                     //Font
          1,                                                      //Scale    
          Scalar(0,0,0),                                          //Colour
          1,                                                      //Thickness
          LINE_4);                                                //line type            
  }
}
