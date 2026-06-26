
#pragma once
#include <string>
#include <vector>
namespace traceweft {
struct PathCheck {
 bool safe=false;
 bool absolute=false;
 bool hasParent=false;
 bool hasControl=false;
 std::string normalized;
 std::vector<std::string> parts;
 }
;
PathCheck NormalizeTracePath(const std::string& path);
bool IsSafeRelativePath(const std::string& path);
std::string JoinPathParts(const std::vector<std::string>& parts);
std::vector<std::string> SplitPath(const std::string& path);
std::string CleanPathForDisplay(const std::string& path);
}
