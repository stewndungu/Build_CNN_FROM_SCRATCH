cmake_minimum_required(VERSION 3.10)
project(BUILD_CNN_FROM_SCRATCH CXX)

add_executable(BUILD_CNN_FROM_SCRATCH 
        xor_test.cpp
        source/vec.cpp
        source/matrix.cpp
        source/activation.cpp 
        source/neuron.cpp 
        source/layer.cpp  
        source/nn.cpp  
        )
set_property(TARGET BUILD_CNN_FROM_SCRATCH PROPERTY CXX_STANDARD 20)

