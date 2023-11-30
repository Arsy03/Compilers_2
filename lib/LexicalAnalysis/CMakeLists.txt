project(LexicalAnalysis)



set(HEADER_FILES
        LexicalAnalyzer.h
        Selectors/SelectorLexeme.h
        Lexeme.h
        Selectors/SelectorWithException.h
        Selectors/FormableTable.h

        TypeLexeme.h
        TableElementLexeme.h
        Selectors/Support/RegexProvider.h
        Selectors/Support/SelectorException.cpp
        Selectors/Support/SelectorException.h
        Selectors/Support/CounterPositionInProgram.h

        Selectors/CommentSelector.h
        Selectors/ConstSelector.h
        Selectors/KeyWordSelector.h
        Selectors/DividerSelector.h
        Selectors/IdentificatorSelector.h
)

set(SOURCE_FILES
        LexicalAnalyzer.cpp

        Selectors/SelectorLexeme.cpp
        Selectors/SelectorWithException.cpp

        TableElementLexeme.cpp
        Selectors/Support/RegexProvider.cpp
        Selectors/Support/SelectorException.cpp
        Selectors/Support/SelectorException.h
        TypeLexeme.cpp

        Selectors/CommentSelector.cpp
        Selectors/ConstSelector.cpp
        Selectors/KeyWordSelector.cpp
        Selectors/DividerSelector.cpp
        Selectors/IdentificatorSelector.cpp
)

add_library(LexicalAnalysis_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

include_directories(../GeneralType)

target_link_libraries(LexicalAnalysis_lib GeneralType_lib)