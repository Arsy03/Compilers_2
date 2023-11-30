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
        TableElementLexeme.h
        Selectors/Support/RegexProvider.h
        Selectors/Support/SelectorException.cpp
        Selectors/Support/SelectorException.h
        Selectors/Support/CounterPositionInProgram.h)

set(SOURCE_FILES
        LexicalAnalyzer.cpp
        Selectors/SelectorLexeme.cpp
        Selectors/SelectorWithException.cpp
        Selectors/CommentSelector.cpp Selectors/ConstSelector.cpp
        TableElementLexeme.cpp
        Selectors/Support/RegexProvider.cpp
        Selectors/Support/SelectorException.cpp
        Selectors/Support/SelectorException.h
        TypeLexeme.cpp)

add_library(LexicalAnalysis_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

include_directories(../GeneralType)

target_link_libraries(LexicalAnalysis_lib GeneralType_lib)