project(Easypp)

include_directories(src)

aux_source_directory(src SRC)

add_library(EasyLogger SHARED ${SRC})