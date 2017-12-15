project(Easypp)

include_directories(src)

aux_source_directory(src SRC)

add_library(EasyJson SHARED ${SRC} src/JsonException.h)