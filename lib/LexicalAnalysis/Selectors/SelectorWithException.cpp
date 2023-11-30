
#include "SelectorWithException.h"
#include "Support/SelectorException.h."


void LexicalAnalysis::Selectors::SelectorWithException::checkOnException(string sourceProgram) {
     vector<entry> exceptions = findAllEntry(sourceProgram, getExceptionRegex());

     if(!exceptions.empty())
         throw SelectorException(getLexType(), exceptions, counterPosition);
}
