#pragma once

#include <string>
#include <vector>

class todo {
public:
   todo() : isResolved(false) {}

   std::string filePath;
   unsigned long lineNumber;

   std::string sectionDate;
   std::string sectionTitle;

   std::string text;

   std::string category;
   bool isResolved;
};

/*
reader + sectionReader
categorizer
histogamer
sorter
formatter : iResult
*/

typedef std::vector<todo> todoList;
