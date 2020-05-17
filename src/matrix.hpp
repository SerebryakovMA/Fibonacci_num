#include <iostream>
#include <vector>

class Matrix {
    public:
    std::vector<int> matrix_composition(std::vector<int> a, std::vector<int> b){//composition of matrices 2x2
        matrix_comp[1] = a[1]*b[1] + a[2]*b[3];
        matrix_comp[2] = a[1]*b[2] + a[2]*b[4];
        matrix_comp[3] = a[3]*b[1] + a[4]*b[3];
        matrix_comp[4] = a[3]*b[2] + a[4]*b[4];
        return matrix_comp; 
    }
    std::vector<int> binpow(std::vector<int> a, int n){  //binary powering for matrix
        if (n == 0){
            a[1] = 1;
            a[2] = 0;
            a[3] = 0;
            a[4] = 1;
            return a;
        }   
        if (n % 2 == 1)
            return matrix_composition(binpow(a, n-1), a);
        else {
            std::vector<int> b = binpow(a, n/2);
            return matrix_composition(b,b);
        }

    }
    std::vector<int> get_matrix(std::vector<int> m){
        return m;
    }
    void set_values(std::vector<int> p){
        initial_matrix = p;
    }
    private:
    std::vector<int> initial_matrix;
    std::vector<int> matrix_comp; //values composition of matrices

};
