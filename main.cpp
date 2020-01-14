#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "Point.h"
#include "ISearchable.h"
#include "SolverSearch.h"
#include "BestFirstSearch.h"
#include "MyClientHandler.h"
#include "AStar.h"
#include "DFS.h"
#include "BFS.h"
#include "Matrix.h"

vector<double> runAlgorithm(ISearchable<Point*>* matrix, Searcher<Point*,string> * search){
  vector<double> result;
  for(int i =0; i<10; i++){
    search->search(matrix);
    result.push_back(search->getNumberOfNodesEvaluated());
  }
  return  result;
}

vector<vector<double >> runAllAlgorithm(ISearchable<Point*>* matrix, vector<Searcher<Point*,string> *> searcher){
  vector<vector<double >> result;
  for(auto s: searcher){
    result.push_back(runAlgorithm(matrix,s));
  }
  return result;
}
string readFromFile(string file) {
  string content ="";
  ifstream inFile(file);
  if (!inFile) {
    throw "Can't open file";
  }
  string line;
  while (std::getline(inFile, line)) {
    content+=line +'\n';
  }
  inFile.close();
  return content;
}
int main() {
  int A[100][100],filas,columnas,m,k,d;
  cout<<"filas";
  cin>>filas;
  cout<<"columnas";
  cin>>columnas;
  d=filas*columnas;
  srand(time(NULL));
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      for (k=1; k<=d; k++){
        m= -1+rand()% (30);
        A[i][j]= m;
      }
    }
  }
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      cout<<A[i][j]<<", ";
    }
    cout<<"\n";
  }
















  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* fileCache= new FileCacheManager();
  Solver<string,string>* solver = new StringReverser();
  string m1 = readFromFile("matrix_test.txt");
//  string m2 = readFromFile("matrix_test.txt");
//  string m3 = readFromFile("matrix_test.txt");
//  string m4 = readFromFile("matrix_test.txt");
//  string m5 = readFromFile("matrix_test.txt");
//  string m6 = readFromFile("matrix_test.txt");
//  string m7 = readFromFile("matrix_test.txt");
//  string m8 = readFromFile("matrix_test.txt");
//  string m9 = readFromFile("matrix_test.txt");
//  string m10 = readFromFile("matrix_test.txt");

  ISearchable<Point*>* matrix1 = new Matrix(m1);
//  ISearchable<Point*>* matrix2 = new Matrix(m2);
//  ISearchable<Point*>* matrix3 = new Matrix(m3);
//  ISearchable<Point*>* matrix4 = new Matrix(m4);
//  ISearchable<Point*>* matrix5 = new Matrix(m5);
//  ISearchable<Point*>* matrix6 = new Matrix(m6);
//  ISearchable<Point*>* matrix7 = new Matrix(m7);
//  ISearchable<Point*>* matrix8 = new Matrix(m8);
//  ISearchable<Point*>* matrix9 = new Matrix(m9);
//  ISearchable<Point*>* matrix10 = new Matrix(m10);


  //searcher
  Searcher<Point*,string> * aStar = new AStar<Point*,string>();
  Searcher<Point*,string> * BestFS = new BestFirstSearch<Point*,string>();
  Searcher<Point*,string> * dfs = new DFS<Point*,string>();
  Searcher<Point*,string> * bfs = new BFS<Point*,string>();

  vector<Searcher<Point*,string>*> searchers;
  searchers.push_back(aStar);
  searchers.push_back(BestFS);
  searchers.push_back(dfs);
  searchers.push_back(bfs);
  cout << dfs->search(matrix1)<<endl;
  double n = dfs->getNumberOfNodesEvaluated();

  //matrix1
//  vector<vector<double >> result1 = runAllAlgorithm(matrix1,searchers);
//  vector<vector<double >> result2 = runAllAlgorithm(matrix2,searchers);
//  vector<vector<double >> result3 = runAllAlgorithm(matrix3,searchers);
//  vector<vector<double >> result4 = runAllAlgorithm(matrix4,searchers);
//  vector<vector<double >> result5 = runAllAlgorithm(matrix5,searchers);
//  vector<vector<double >> result6 = runAllAlgorithm(matrix6,searchers);
//  vector<vector<double >> result7 = runAllAlgorithm(matrix7,searchers);
//  vector<vector<double >> result8 = runAllAlgorithm(matrix8,searchers);
//  vector<vector<double >> result9 = runAllAlgorithm(matrix9,searchers);
//  vector<vector<double >> result10 = runAllAlgorithm(matrix10,searchers);



  //solvers
  Solver<ISearchable<Point*>*,string> *solverAStar = new SolverSearch<ISearchable<Point*>*,string,Point*>(aStar);
  Solver<ISearchable<Point*>*,string> *solverBestFS = new SolverSearch<ISearchable<Point*>*,string,Point*>(BestFS);
  Solver<ISearchable<Point*>*,string> *solverDFS = new SolverSearch<ISearchable<Point*>*,string,Point*>(dfs);
  Solver<ISearchable<Point*>*,string> *solverBFS = new SolverSearch<ISearchable<Point*>*,string,Point*>(bfs);


  //clients
  ClientHandler *c1  = new MyClientHandler(solverBestFS,fileCache);
//  ClientHandler *c2  = new MyClientHandler(solverS,fileCache);
//  ClientHandler *c3  = new MyClientHandler(solverS,fileCache);
//  ClientHandler *c4  = new MyClientHandler(solverS,fileCache);

  s->open(12345, c1);


  delete fileCache;
  delete(solver);
  delete(c1);
  return 0;
}
