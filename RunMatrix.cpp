//
// Created by shirgold on 15/01/2020.
//


#include "RunMatrix.h"

vector<double> RunMatrix::runAlgorithm(ISearchable<Point *> *matrix, Searcher<Point *, string> *search) {
    vector<double> result;
    for (int i = 0; i < 10; i++) {
        search->search(matrix);
        result.push_back(search->getNumberOfNodesEvaluated());
    }
    return result;
}

vector<vector<double >> RunMatrix::runAllAlgorithm(ISearchable<Point *> *matrix,
                                                   vector<Searcher<Point *, string> *> searcher) {
    vector<vector<double >> result;
    for (auto s: searcher) {
        result.push_back(runAlgorithm(matrix, s));
    }
    return result;
}

string RunMatrix::readFromFile(string file) {
    string content = "";
    ifstream inFile(file);
    if (!inFile) {
        throw "Can't open file";
    }
    string line;
    while (std::getline(inFile, line)) {
        content += line + '\n';
    }
    inFile.close();
    return content;
}