#include <cmath>

namespace sums {
    double sum_above_main_d(int n, double** matrix){
        double result = 0;
        for(int i = 0, j = 0; i < n; ++j){
            if(j == n) ++i, j = i;
            if(i == n) break;
            result += matrix[i][j];
        }
        return result;
    }
    double sum_above_diag(int n, double** matrix){
        double result = 0;
        for(int i = 0, j = 0;; ++j){
            if(j == n - i) ++i, j = i;
            if(i == n / 2){
                if(n % 2 == 0) break;
                else{
                    result += matrix[i][j];
                    break;
                }
            }            
            result += matrix[i][j];
        }
        return result;
    }
    double sum_left_right(int n, double** matrix){
        double result = 0;
        bool not_center;
        if(n % 2 != 0) not_center = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if((j + 1 == n - j) && (i + 1 == n - 1) && not_center) continue;
                if(i < n / 2){
                    result += matrix[i][j];
                }
                else if (j <= n - i - 1){
                    result += matrix[i][j];
                }
            }
            for(int j = n; j >= n - i - 1; --j){
                if(i < n / 2){
                    result += matrix[i][j];
                } else if (j >= i){
                    result += matrix[i][j];
                }
            }
        }
        return result;
        }
    double sum_all_within_high_triangle(int n, double** matrix){
        double result = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                result += matrix[i][j];
                if((i == j || j == n - i - 1) && (n % 2 != 0 ? i <= n / 2 : i < n / 2)) result += matrix[i][j];
            }
        }
        return result;
    }
}