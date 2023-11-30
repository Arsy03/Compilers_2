project(GeneralType)

set(HEADER_FILES
        Table/Table.h
        Table/TableRow.h
        Table/OutputTable.h
)

set(SOURCE_FILES
        Table/Table.cpp
        Table/OutputTable.cpp
)

add_library(GeneralType_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})