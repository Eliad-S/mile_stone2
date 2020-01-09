//
// Created by eliadsellem on 1/6/20.
//
#include <unordered_map>
#include <fstream>
#include "CacheManager.h"
using namespace std;
#ifndef MILE_STONE2__FILECACHEMANAGER_H_
#define MILE_STONE2__FILECACHEMANAGER_H_
template<typename P, typename S>
class FileCacheManager : public CacheManager<P,S> {
  // <problem, solution>
  unordered_map<P, S> cacheMap;
  hash<string> hasher;

 public:

  virtual bool isSolved(P problem) {
    if (cacheMap.find(problem) != cacheMap.end() || exist(problem)) {
      return true;
    }
    return false;
  }
  virtual S getSolution(P problem) {
    auto item = cacheMap.find(problem);
    //if the key doesn't exist
    if (item == cacheMap.end()) {
      //search in the disk first.
      if (!exist(problem)) {
        throw "Error: The key doesn't existing";
      }
      //read object from file.
      S solution = this->readObj(problem,solution);

      size_t hash = hasher(problem);
      cacheMap[to_string(hash)] = solution;
      return solution;
    } else {
      return item->second;
    }
  }

  virtual void saveSolution(P problem, S &solution) {
    //will always be string
    size_t hash = hasher(problem);
    cacheMap[to_string(hash)] = solution;
    ofstream outFile(to_string(hash), std::ios::binary);
    if (!outFile) {
      throw "File create error";
    }
    outFile.write((char *) &solution, sizeof(solution));
    outFile.close();
  }

  S &readObj(P problem, S &solution) {
    size_t hash = hasher(problem);
    ifstream inFile(to_string(hash), std::ios::binary);
    if (!inFile) {
      throw "Can't open file";
    }
    inFile.read((char *) &solution, sizeof(solution));
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
