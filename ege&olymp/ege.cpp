#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int main() {
    string m;
    cin >> m;
    ifstream fin(m);
    //ifstream fin("test.txt");

    int n;
    fin >> n;
    const int t = n;
    vector<vector<int>> A;

    unsigned long long mins = 0;
    unsigned long long kr = 0, sr = 0;
    unsigned long long sl = 0, kl = 0;
    for (int i = 0;i < t;i++) {
        vector<int> t;
        int t1, t2;
        fin >> t1 >> t2;
        t.push_back(t1);
        t.push_back(t2); 
        A.push_back(t);
    }

    sort(A.begin(), A.end(), comp);

    //for (size_t i = 1;i < A.size();i++) { cout << A[i][0] << " " << A[i][1] << endl; }

    for (size_t i = 1;i < A.size();i++) { 
        sr += (A[i][1] * (A[i][0] - A[0][0])); 
        kr += A[i][1]; 
    }
    mins = sr;

    int mini;
    for(size_t i = 1; i < A.size(); i++) {
        sr -= (kr * (A[i][0] - A[i-1][0]));
        kr -= A[i][1];
        kl += A[i-1][1];
        sl += (kl * (A[i][0] - A[i-1][0]));
        if (sr + sl < mins) {
            mins = sr + sl;
            mini = A[i][0];
        }
    }

    cout << mini << endl << mins << endl;
    return 0;
}   