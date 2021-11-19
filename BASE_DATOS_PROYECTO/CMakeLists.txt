project( MISION_IMPOSIBLE )

add_executable(${PROJECT_NAME}_EJECUTAME tablas.cpp )

target_link_libraries (${PROJECT_NAME}_EJECUTAME sqlite3 )
