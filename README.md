# Proyecto1_IE0724

En este proyecto, se desarrolló un programa capaz de calcular, a partir de una entrada en formato .txt que contiene una serie de puntos, cuales de esos puntos conforman el convex hull del grupo. A parte de eso, logra construir una imagen en formato .png para visualizar la forma del convex hull junto con los puntos.  

## Librerias necesarias

Se necesitan las siguientes librerias:

-[CGAL](https://doc.cgal.org/latest/Manual/general_intro.html)

-[OpenCV](https://docs.opencv.org/master/d2/de6/tutorial_py_setup_in_ubuntu.html)


## Uso

En la carpeta que dice build, se deben correr los siguientes comandos

```bash
cmake .. 
make
./exe 
```
Lo anterior imprime todas las pruebas una vez y dice si pasaron o no las pruebas. 

En caso de querer correr la prueba 2 10 veces se debe usar el siguiente comando de ejecucion

```bash
./exe --gtest_filter=ConvexHull.positive --gtest_repeat=10
```
