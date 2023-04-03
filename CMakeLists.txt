cmake_minimum_required(VERSION 3.25)


project(CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize= address leak thread undefined memory [additional_options] [-g] [-OX]")