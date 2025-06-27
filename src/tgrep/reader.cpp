#include "error.hpp"
#include "reader.hpp"
#include "string.hpp"
#include <fstream>
#include <iostream>

namespace {

class reader {
public:
   static void read(const std::string& fpath, todoList& tl)
   { reader(tl).read(fpath); }

private:
   explicit reader(todoList& tl) : m_lineNumber(0), m_tl(tl) {}

   void read(const std::string& fpath)
   {
      std::ifstream file(fpath);
      if(!file.good())
         error(errLoc,"can't open file")
            .with("file path",fpath)
            .raise();

      m_filePath = fpath;
      do
      {
         std::string line;
         std::getline(file,line);
         ++m_lineNumber;
         online(line);
      }
      while(file.good());
   }

   void online(const std::string& line)
   {
      auto trimmed = trimLeadingWhitespace(line);
      if(trimmed.length() > 2 && trimmed.c_str()[0] == '[' && trimmed.c_str()[2] == ']')
         createTodo(trimmed);
   }

   void createTodo(const std::string& line)
   {
      std::cout << "capturing todo for line '" << line << "'" << std::endl;

      m_tl.push_back(todo());
      auto& t = m_tl.back();

      t.filePath = m_filePath;
      t.lineNumber = m_lineNumber;
      t.sectionDate = m_sectionDate;
      t.sectionTitle = m_sectionTitle;
      t.text = line;
   }

   std::string m_filePath;
   unsigned long m_lineNumber;
   std::string m_sectionDate;
   std::string m_sectionTitle;

   todoList& m_tl;
};

} // anonymous namespace

void readTextFile(const std::string& fpath, todoList& tl)
{ reader::read(fpath,tl); }
