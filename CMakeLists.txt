cmake_minimum_required(VERSION 3.0)
project(acm)

set(CMAKE_CXX_STANDARD 14)

add_executable(acm main.cpp)

add_executable(A hnie/6.9/A.cpp)
add_executable(C hnie/5.31/C.cpp)
add_executable(D hnie/5week/D.cpp)
add_executable(E hnie/3week/E.cpp)
add_executable(B hnie/6.2/B.cpp)
add_executable(I vj/10.3/I.cpp)

add_executable(p2635 poj/p2635.cpp)

add_executable(sqlist hnie/11.13/sqlist.cpp hnie/11.13/sqlist.h)

add_executable(12.10 hnie/12.10.cpp hnie/Demo/Demo.cpp)

add_executable(exp6 hnie/12.17/exp6.cpp)

add_executable(F vj/3.12/F.cpp)
add_executable(exp7 hnie/12.17/exp7.cpp)
add_executable(exp8 hnie/12.17/exp8.cpp)
add_executable(exp9 hnie/12.17/exp9.cpp)
add_executable(exp10 hnie/12.17/exp10.cpp)

add_executable(teacher poj/teacher.cpp poj/teacher.h)
add_executable(test poj/test.cpp)

add_executable(tmp vj/3.12/tmp.cpp)
add_executable(TT vj/3.12/TT.cpp)

add_executable(G hnie/3week/G.cpp)

add_executable(Demo hnie/Demo/Demo.cpp)


add_executable(Demo_2 hnie/4week/Demo_2.cpp)
add_executable(YES hnie/5week/YES.cpp)
add_executable(Server hnie/5week/Server.cpp)

add_executable(AC hnie/6.2/AC.cpp)
