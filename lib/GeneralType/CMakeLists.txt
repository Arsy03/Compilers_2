project(GeneralType)

set(HEADER_FILES
        Table.h
        TableRow.h
)

set(SOURCE_FILES
        Table.cpp
)

add_library(GeneralType_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})