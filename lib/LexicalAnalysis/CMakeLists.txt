project(LexicalAnalysis)



set(HEADER_FILES
        LexicalAnalyzer.h
        Selectors/SelectorLexeme.h
        Lexeme.h
        Selectors/SelectorWithException.h
        Selectors/FormableTable.h
        Selectors/CommentSelector.h
        TypeLexeme.h
        Selectors/ConstSelector.h
        TableElementLexeme.h)

set(SOURCE_FILES
        LexicalAnalyzer.cpp
        Selectors/SelectorLexeme.cpp
        Selectors/SelectorWithException.cpp
        Selectors/CommentSelector.cpp Selectors/ConstSelector.cpp
        TableElementLexeme.cpp)

add_library(LexicalAnalysis_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

include_directories(../GeneralType)

target_link_libraries(LexicalAnalysis_lib GeneralType_lib)