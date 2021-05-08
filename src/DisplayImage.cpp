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
//void MyFilledCircle( Mat img, Point center );
void MyLine( Mat img, Point start, Point end );

int main (void){
    char hull_window[] = "Drawing: Convex Hull";
    //vector <float> puntos{0, 0, 10, 0, 10, 10, 0, 10};
    vector <float> puntos{-40, 70, 80, -50, -80, -65};
    //normalizamos los puntos y luego los escalamos al tamano de ventana
    float max = *max_element(puntos.begin(), puntos.end());
    float min = *min_element(puntos.begin(), puntos.end());
    for (int i = 0; i < puntos.size(); i++) {
        puntos[i] = (puntos[i] - min) / (max - min); //normalizamos el vector
        puntos[i] = puntos[i] * 280 + 60;    //lo ajustamos al rango de 60 a 340
    }
    //std::transform(puntos.begin(),puntos.end(),puntos.begin(),
    //  std::bind(std::multiplies<float>(), std::placeholders::_1,escalar));
    Mat hull_image = Mat::zeros( w, w, CV_8UC3 );
    putText(hull_image,"OpenCV",Point(w/2,w/2),FONT_HERSHEY_SIMPLEX,0.5,(255,255,255),2);

    //creamos lineas
    for (int i=0; i < puntos.size();i=i+2){
      if (i != puntos.size()-2) {
        MyLine(hull_image, Point(puntos[i], w - puntos[i+1]), 
        Point(puntos[i+2] , w - puntos[i+3]));
      }
      else
        MyLine(hull_image, Point(puntos[i], w - puntos[i+1]), 
        Point(puntos[0], w - puntos[1]));
    }
    //construimos la imagen  
    imshow( hull_window, hull_image );
    moveWindow( hull_window, 0, 200 );
    waitKey( 0 );
    return(0);
}

//funcion para lineas
void MyLine( Mat img, Point start, Point end )
{
  int thickness = 2;
  int lineType = LINE_8;
  line( img,
    start,
    end,
    Scalar( 0, 255, 0 ),
    thickness,
    lineType );
}
