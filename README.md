# Laboratorio 4

En base a lo hecho en el proyecto 1, se desarrollo este programa Gtest, para hacer las pruebas de validacion del codigo hecho. Se modifico el codigo del proyecto para que manejara excepciones y en caso de que se fuerce una el programa no se caiga. 

Se intento configurar el docker pero opencv no quiere compilar en el docker por lo que se adjunta el archivo docker pero solo se pueden los codigos gtest

## Librerias necesarias

Se necesitan las siguientes librerias:

-[CGAL](https://doc.cgal.org/latest/Manual/general_intro.html)

-[OpenCV](https://docs.opencv.org/master/d2/de6/tutorial_py_setup_in_ubuntu.html)


## Uso

En la carpeta que dice build2, se deben correr los siguientes comandos

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
