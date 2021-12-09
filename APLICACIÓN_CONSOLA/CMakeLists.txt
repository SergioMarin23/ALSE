project(APLICACION_CONSOLA)

add_executable(APP_CONSOLA_PF
               sensor.cpp
               sensor.h
               db_local.cpp
               db_local.h
               main.cpp)

target_link_libraries( APP_CONSOLA_PF sqlite3 )
