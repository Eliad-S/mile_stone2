//
// Created by eliadsellem on 1/6/20.
//
#include <unordered_map>
#include <fstream>
#include "CacheManager.h"
using namespace std;
#ifndef MILE_STONE2__FILECACHEMANAGER_H_
#define MILE_STONE2__FILECACHEMANAGER_H_
class FileCacheManager : public CacheManager<string,string> {
  // <problem, solution>
  unordered_map<string, string> cacheMap;
  hash<string> hasher;

 public:

  virtual bool isSolved(string problem) {
    if (cacheMap.find(problem) != cacheMap.end() || exist(problem)) {
      return true;
    }
    return false;
  }
  virtual string getSolution(string problem) {
    auto item = cacheMap.find(problem);
    //if the key doesn't exist
    if (item == cacheMap.end()) {
      //search in the disk first.
      if (!exist(problem)) {
        throw "Error: The key doesn't existing";
      }
      //read object from file.
      string solution = this->readObj(problem);

      size_t hash = hasher(problem);
      cacheMap[to_string(hash)] = solution;
      return solution;
    } else {
      return item->second;
    }
  }

  virtual void saveSolution(string problem, string &solution) {
    //will always be string
    size_t hash = hasher(problem);
    cacheMap[problem] = to_string(hash);
    ofstream outFile(to_string(hash));
    if (!outFile) {
      throw "File create error";
    }
    outFile<<solution;
    outFile.close();
  }

  string readObj(string problem) {
    string solution ="";
    size_t hash = hasher(problem);
    ifstream inFile(to_string(hash));
    if (!inFile) {
      throw "Can't open file";
    }
    string line;
    while (inFile >> line) {
      solution += line;
    }
    inFile.close();
    return solution;
  }


  inline bool exist(const std::string &name) {
    size_t hash = hasher(name);
    ifstream file(to_string(hash));
    if (!file)            // If the file was not found, then file is 0, i.e. !file=1 or true.
      return false;    // The file was not found.
    else                 // If the file was found, then file is non-0.
      return true;     // The file was found.
  }
};

#endif //MILE_STONE2__FILECACHEMANAGER_H_
