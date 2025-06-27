#pragma once
#include <functional>
#include <string>

void forEachFile(const std::string& path, std::function<void(const std::string&)> onFile);
