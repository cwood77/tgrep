#include "commandLine.hpp"
#include "error.hpp"
#include "finder.hpp"
#include "reader.hpp"
#include <iostream>

namespace {

void printUsage()
{
   std::cout
      << "tgrep - search for todos in text files and report on them" << std::endl
      << "usage:" << std::endl
#if 0 // coming soon
      << "   --hist                    - show a histogram of todos" << std::endl
#endif
      << "   --cat [--all]             - categorize todos, and show unresolved" << std::endl
#if 0 // coming soon
      << "   --launch [category] [exe] - apply window state from file" << std::endl
#endif
   ;
}

} // anonymous namespace

int main(int argc, const char *argv[])
{
   try
   {
      commandLine cl(argc,argv);

      if(cl.reset().literal("--help").end())
         printUsage();
      else if(cl.reset().literal("--cat").end())
      {
         todoList tl;
         forEachFile(".",[&](auto& fp)
         {
            std::cout << "reading file '" << fp << "'" << std::endl;
            readTextFile(fp,tl);
         });
      }
      else
         error(errLoc,"bad usage; use --help")
            .raise();

      return 0;
   }
   catch(std::exception& x)
   {
      std::cerr << "ERROR: " << x.what() << std::endl;
      return -1;
   }
}
