#include "EigenTutorial.hh"

using namespace std;

void EigenTutorial::solve_sparse_linear_system() {
    SMatd A(5,5);
    std::vector<T> tripletList;
    VecXd b(5), x(5);

    //This is a small sparse linear system Ax = b, where
    //     | 2  3  0  0  0 |
    //     | 3  0  4  0  6 |
    // A = | 0 -1 -3  2  0 |
    //     | 0  0  1  0  0 |
    //     | 0  4  2  0  1 |
    //and b is (8  45  -3  3  19)T. Read the documentation of Eigen on sparse linear
    //algebra (http://eigen.tuxfamily.org/dox-3.2/group__Sparse__chapter.html).
    //Solve the system and output the value of A, x and b.

    //Add your code here

    SolLU solver;

    tripletList.push_back(T(0,0,2.0));
    tripletList.push_back(T(0,1,3.0));
    tripletList.push_back(T(1,0,3.0));
    tripletList.push_back(T(1,2,4.0));
    tripletList.push_back(T(1,4,6.0));
    tripletList.push_back(T(2,1,-1.0));
    tripletList.push_back(T(2,2,-3.0));
    tripletList.push_back(T(2,3,2.0));
    tripletList.push_back(T(3,2,1.0));
    tripletList.push_back(T(4,1,4.0));
    tripletList.push_back(T(4,2,2.0));
    tripletList.push_back(T(4,4,1.0));

    A.setFromTriplets(tripletList.begin(), tripletList.end());

    b << 8, 45, -3, 3, 19;

    //solver.analyzePattern(A);
    //solver.factorize(A);
    solver.compute(A);

    x = solver.solve(b);

    cout << "\nMatrix A:\n" << A << endl;
    cout << "\nVector b:\n" << b << endl;
    cout << "\nSolution x:\n" << x << endl;


}
