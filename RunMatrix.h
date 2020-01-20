//
// Created by shirgold on 15/01/2020.
//
#ifndef MILE_STONE2_RUNMMATRIX_H
#define MILE_STONE2_RUNMMATRIX_H
#include <fstream>
#include <vector>
#include <string>
#include "Point.h"
#include "ISearchable.h"
#include "Searcher.h"
#include "MySerialServer.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "AStar.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
using namespace std;
class RunMatrix {
public:
    /*
     * the function run specific algorithm on specific matrix
     */
    static vector<double> runAlgorithm(ISearchable<Point*>* matrix, Searcher<Point*,string> * search);
    /*
     * the function run all the algorithms with the given matrix
     */
    static vector<vector<double >> runAllAlgorithm(ISearchable<Point*>* matrix, vector<Searcher<Point*,string> *> searcher);
    /*
     * the function read matrix from file
     */
    static string readFromFile(string file);
    static map<string, vector<vector<double >>> returnResults(CacheManager<string, string>* fileCache) {
        MySerialServer* s = new MySerialServer();
        Solver<string,string>* solver = new StringReverser();

        // read matrix
        string m1 = readFromFile("matrix1.txt");
        string m2 = readFromFile("matrix2.txt");
        string m3 = readFromFile("matrix3.txt");
        string m4 = readFromFile("matrix4.txt");
        string m5 = readFromFile("matrix5.txt");
        string m6 = readFromFile("matrix6.txt");
        string m7 = readFromFile("matrix7.txt");
        string m8 = readFromFile("matrix8.txt");
        string m9 = readFromFile("matrix9.txt");
        string m10 = readFromFile("matrix10.txt");

        // create matrix
        ISearchable<Point*>* matrix1 = new Matrix(m1);
        ISearchable<Point*>* matrix2 = new Matrix(m2);
        ISearchable<Point*>* matrix3 = new Matrix(m3);
        ISearchable<Point*>* matrix4 = new Matrix(m4);
        ISearchable<Point*>* matrix5 = new Matrix(m5);
        ISearchable<Point*>* matrix6 = new Matrix(m6);
        ISearchable<Point*>* matrix7 = new Matrix(m7);
        ISearchable<Point*>* matrix8 = new Matrix(m8);
        ISearchable<Point*>* matrix9 = new Matrix(m9);
        ISearchable<Point*>* matrix10 = new Matrix(m10);


        //searchers
        Searcher<Point*,string> * aStar = new AStar<Point*,string>();
        Searcher<Point*,string> * BestFS = new BestFirstSearch<Point*,string>();
        Searcher<Point*,string> * dfs = new DFS<Point*,string>();
        Searcher<Point*,string> * bfs = new BFS<Point*,string>();

        // vector of searchers
        vector<Searcher<Point*,string>*> searchers;
        searchers.push_back(aStar);
        searchers.push_back(BestFS);
        searchers.push_back(dfs);
        searchers.push_back(bfs);


        // results
        vector<vector<double >> result1 = runAllAlgorithm(matrix1,searchers);
        vector<vector<double >> result2 = runAllAlgorithm(matrix2,searchers);
        vector<vector<double >> result3 = runAllAlgorithm(matrix3,searchers);
        vector<vector<double >> result4 = runAllAlgorithm(matrix4,searchers);
        vector<vector<double >> result5 = runAllAlgorithm(matrix5,searchers);
        vector<vector<double >> result6 = runAllAlgorithm(matrix6,searchers);
        vector<vector<double >> result7 = runAllAlgorithm(matrix7,searchers);
        vector<vector<double >> result8 = runAllAlgorithm(matrix8,searchers);
        vector<vector<double >> result9 = runAllAlgorithm(matrix9,searchers);
        vector<vector<double >> result10 = runAllAlgorithm(matrix10,searchers);

        // map of results
        map<string, vector<vector<double >>> map;
        map["matrix1"] = result1;
        map["matrix2"] = result2;
        map["matrix3"] = result3;
        map["matrix4"] = result4;
        map["matrix5"] = result5;
        map["matrix6"] = result6;
        map["matrix7"] = result7;
        map["matrix8"] = result8;
        map["matrix9"] = result9;
        map["matrix10"] = result10;

        // return all results
        return map;
    }
};


#endif //MILE_STONE2_RUNMMATRIX_H
