#include "string.hpp"
#include <cstring>

bool endsWith(const std::string& s, const std::string& suffix)
{
   if(s.length() < suffix.length())
      return false;
   return ::strncmp(s.c_str()+s.length()-suffix.length(),suffix.c_str(),suffix.length())==0;
}

std::string trimLeadingWhitespace(const std::string& s)
{
   const char *pThumb = s.c_str();
   for(;*pThumb==' '||*pThumb=='\t';++pThumb);
   return pThumb;
}
