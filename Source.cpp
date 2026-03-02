#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return -1;
    }

    const int N = atoi(argv[1]);
    cout << "Matrix size: " << N << "x" << N << endl;

    double* A = new double[N * N];
    double* B = new double[N * N];
    double* C = new double[N * N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i * N + j] = (i + 1) * (j + 1);
            B[i * N + j] = (i + 1) + 2 * (j + 1);
        }
    }

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i * N + j] = 0;
            for (int k = 0; k < N; k++) {
                C[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    }

    double elapsed = double(clock() - start) / CLOCKS_PER_SEC;
    double operations = 2.0 * N * N * N;

    cout << "\nTime: " << elapsed << " seconds" << endl;
    cout << "Size: " << N << "x" << N << endl;
    cout << "Operations: ~" << operations << endl;

    ofstream out("matrix_C.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out << C[i * N + j] << " ";
        }
        out << endl;
    }
    out.close();

    ofstream outA("matrix_A.txt"), outB("matrix_B.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            outA << A[i * N + j] << " ";
            outB << B[i * N + j] << " ";
        }
        outA << endl;
        outB << endl;
    }
    outA.close();
    outB.close();

    cout << "\nFiles saved. Run verify.py to check." << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}