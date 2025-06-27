#define WIN32_LEAN_AND_MEAN
#include "error.hpp"
#include "finder.hpp"
#include "string.hpp"
#include <windows.h>

namespace {

class finder {
public:
   explicit finder(std::function<void(const std::string&)> onFile) : m_callback(onFile) {}

   void recurse(const std::string& path)
   {
      WIN32_FIND_DATA fData;
      HANDLE hFind = ::FindFirstFileA((path + "\\*.*").c_str(),&fData);
      if(hFind == INVALID_HANDLE_VALUE)
         error(errLoc,"path can't be read")
            .with("path",path)
            .raise();
      do
      {
         if(std::string(".") == fData.cFileName)
            continue;
         if(std::string("..") == fData.cFileName)
            continue;

         std::string fullPath = path + "\\" + fData.cFileName;

         if(fData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            recurse(fullPath);
         else if(endsWith(fullPath,".txt"))
            m_callback(fullPath);
      }
      while(::FindNextFileA(hFind,&fData));

      ::FindClose(hFind);
   }

private:
   std::function<void(const std::string&)> m_callback;
};

} // anonymous namespace

void forEachFile(const std::string& path, std::function<void(const std::string&)> onFile)
{ finder(onFile).recurse(path); }
