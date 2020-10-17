cmake_minimum_required(VERSION 3.10)

set (PROJECT main_test) 
 
project (${PROJECT}) 


 
set (HEADERS 
    mem.h
    hash.h
    cells.h
    
)
 
set (SOURCES 
    main.c
    mem.c
    hash.c
    cells.c
 
)
#add_definitions(${MYCOMPILE_FLAGS})
#LIST(append CMAKE_C_FLAGS ${MYCOMPILE_FLAGS })
#SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -lm")
#target_compile_features(${PROJECT} -lm)
#target_compile_options(${PROJECT} -lm)
add_executable (${PROJECT} ${HEADERS} ${SOURCES})
