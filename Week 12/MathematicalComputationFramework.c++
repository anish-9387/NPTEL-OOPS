#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<fstream>
#include<sstream>
#include<stdexcept>
using namespace std;

class MatrixOperations{
public:
    vector<vector<double>> add(const vector<vector<double>>& A, const vector<vector<double>>& B);
};

class EquationSolver{
public:
    pair<double, double> solveQuadratic(double a, double b, double c);
};

class Statistics{
public:
    double mean(const vector<double>& data);
};

// Helper functions for loading data from files
vector<double> loadData(const string& filename){
    vector<double> data;
    ifstream file(filename);
    if(!file)   throw runtime_error("Unable to open data file");
    double value;
    while(file>>value){
        data.push_back(value);
    }
    return data;
}

vector<vector<double>> loadMatrix(const string& filename) {
    vector<vector<double>> matrix;
    ifstream file(filename);
    if(!file)   throw runtime_error("Unable to open matrix file");
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        vector<double> row;
        double value;
        while(iss>>value) {
            row.push_back(value);
        }
        if(!row.empty()){
            matrix.push_back(row);
        }
    }
    return matrix;
}

// Class Method Definitions
vector<vector<double>> MatrixOperations::add(const vector<vector<double>>& A, const vector<vector<double>>& B){
    if(A.size()!=B.size() || A[0].size()!=B[0].size()){
        throw invalid_argument("Matrix dimensions must match");
    }
    vector<vector<double>> result(A.size(), vector<double>(A[0].size(), 0));

    for(size_t i=0; i<A.size(); ++i){
        for(size_t j=0; j<A[0].size(); ++j){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}

pair<double,double> EquationSolver::solveQuadratic(double a, double b, double c){
    double discriminant=b*b-4*a*c;
    if(discriminant<0)   throw runtime_error("No real roots");
    double root1=(-b+sqrt(discriminant))/(2*a);
    double root2=(-b-sqrt(discriminant))/(2*a);
    return { root1, root2 };
}

double Statistics::mean(const vector<double>& data){
    return accumulate(data.begin(),data.end(),0.0)/data.size();
}

void saveResults(const vector<double>& results, const vector<vector<double>>& matrixResult, const string& filename){
    ofstream file(filename);
    if(!file){
        throw runtime_error("Unable to open file for writing");
    }
    file<<"# Results"<<endl;
    file<<"Quadratic Equation Roots:"<<endl;
    file<<"Root 1: "<< results[0]<<endl;
    file<<"Root 2: "<< results[1]<<"\n\n";

    file<<"Mean Calculation:"<<endl;
    file<<"Mean: "<<results[2]<<"\n\n";

    file<<"Matrix Addition Result:"<<endl;
    for(const auto& row : matrixResult){
        for(const auto& val : row){
            file<<val<<" ";
        }
        file<<endl;
    }
    file.close();
}

int main(){
    MatrixOperations matrixOps;
    EquationSolver solver;
    Statistics stats;

    vector<double> results;
    vector<vector<double>> matrixResult;

    // Eg 1: Solve quadratic equation
    auto roots=solver.solveQuadratic(1,-3,2);
    cout<<"Roots: "<<roots.first<<", "<<roots.second<<endl;
    results.push_back(roots.first);
    results.push_back(roots.second);

    // Eg 2: Mean calculation
    try{
        auto data=loadData("data.txt");
        double meanValue=stats.mean(data);
        cout<<"Mean: "<<meanValue<<endl;
        results.push_back(meanValue);
    }
    catch(const exception& e){
        cout<<"Error loading data: "<<e.what()<<endl;
        results.push_back(0);
    }

    // Eg 3: Matrix addition
    try{
        auto matrixA=loadMatrix("matrixA.txt");
        auto matrixB=loadMatrix("matrixB.txt");
        matrixResult=matrixOps.add(matrixA, matrixB);
        cout<<"Matrix Addition result:"<<endl;
        for(const auto& row : matrixResult){
            for(const auto& val : row){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }

    // Save all results to a file
    saveResults(results, matrixResult, "results.txt");
    cout<<"Results saved to results.txt" << endl;

    return 0;
}