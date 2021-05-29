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
        build-essential cmake libgtest-dev git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev libcgal-dev\    
    && cd /usr/src/gtest/ \
    && cmake CMakeLists.txt \
    && make  \
    && cd ~ \
    && cd /opt \
    && git clone https://github.com/Itseez/opencv.git \
    && git clone https://github.com/Itseez/opencv_contrib.git \
    && cd opencv \
    && mkdir release \
    && cd release \
    && cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D OPENCV_GENERATE_PKGCONFIG=ON -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/ \
    && make j4 \
    && make install \
    && ldconfig \
    && exit \
    && cd ~ \
    
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
