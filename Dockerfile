# Definimos OS base
FROM ubuntu:20.04

ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone


LABEL version="1.0"
LABEL description="Custom docker image for a Gtest example"

# Choose user root
USER root
RUN apt-get update \
    && apt-get --yes --no-install-recommends install \
        build-essential cmake libgtest-dev git wget unzip libcgal-dev\    
    && cd /usr/src/gtest/ \
    && cmake CMakeLists.txt \
    && make \ 
    && cd ~ \
    && wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip \
    && unzip opencv.zip \
    && mkdir -p build && cd build \
    && cmake  ../opencv-master \
    && cmake --build .

    
# Crear carpeta del proyecto
RUN mkdir -p /home/gtest/lab4

# copio archivos
COPY include /home/gtest/lab4/include
COPY src /home/gtest/lab4/src
COPY test /home/gtest/lab4/test
COPY CMakeLists.txt /home/gtest/lab4/CMakeLists.txt

# DEBUG: imprimir los contenidos
RUN mkdir /home/gtest/lab4/build \
    && cd /home/gtest/lab4/build \
    && cmake .. \
    && make \
    && cp exe /usr/bin/run_unittest \
    && chmod +x /usr/bin/run_unittest
