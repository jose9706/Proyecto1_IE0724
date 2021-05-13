# Proyecto1_IE0724

En este proyecto, se desarrolló un programa capaz de calcular, a partir de una entrada en formato .txt que contiene una serie de puntos, cuales de esos puntos conforman el convex hull del grupo. A parte de eso, logra construir una imagen en formato .png para visualizar la forma del convex hull junto con los puntos.  

## Librerias necesarias

Se necesitan las siguientes librerias:

-[CGAL](https://doc.cgal.org/latest/Manual/general_intro.html)

-[OpenCV](https://docs.opencv.org/master/d2/de6/tutorial_py_setup_in_ubuntu.html)


## Uso

En la carpeta inicial, se deben correr los siguientes comandos

```bash
cmake . 
make
./exe <archivo txt con las entradas> #retorna los puntos leidos + la imagen
```
