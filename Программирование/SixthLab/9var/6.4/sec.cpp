template<class usertype>
int swap_main(int n, usertype** matrix){
    usertype** tmp = new usertype*[n / 2];
    for(int i = 0; i < n / 2; ++i){
        tmp[i] = new usertype[n / 2];
        for(int j = n / 2; j < n; ++j){
            tmp[i][j - n / 2] = matrix[i][j];
            matrix[i][j] = matrix[i][j - n / 2];
            matrix[i][j - n / 2] = matrix[i + n / 2][j - n / 2];
        }
    }
    for(int i = n / 2; i < n; ++i){
        for(int j = 0; j < n / 2; ++j){
            matrix[i][j] = matrix[i][j + n / 2];
            matrix[i][j + n / 2] = tmp[i - n / 2][j];
        }
    }

    return 0;
};