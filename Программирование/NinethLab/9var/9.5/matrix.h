#pragma once

/*---M--E--T--H--O--D--S-----------------------------------
void Set(int i, int j, int value) - ������������ �������� [i][j] �������� value
void Set(int value) - ������������ ������� �������� ������� �������� value
UT Get(int i, int j) - ��������� �������� �������� [i][j]
void GetMinVector(UT* vector) - ������ � ������ vector ������� �� ����������� �������� ��������
int GetColNumber() - ��������� ���������� ��������
int GetRowNumber() - ��������� ���������� �����
UT ColMax(int j) - ��������� ������������� �������� ������� j
UT ColMin(int j) - ��������� ������������ �������� ������� j
UT Biggest() - ��������� ������������� �������� �������
UT Smallest() - ��������� ������������ �������� �������
UT RowSumm(int i) - ��������� ����� ��������� ������ i
UT ColSumm(int j) - ��������� ����� ��������� ������� j
char* GetName() - ��������� ����� �������
Matrix Power(int n) - ���������� ������� � ������� n
----------------------------------------------------*/


template <typename UT = double> //��� �� ��������� double, ��� ����� ����� ���������������� ��� Matrix <>obj;
class Matrix {
    private:
        UT** matrix;
        int i, j, id;
        static inline int count() { static int _storage = 0; return _storage++; } //������� ��������
        char *name;
    public:
        Matrix(){ //���������� ��� ����������
            i = j = 50;
            id = count();
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] = 0;
                }
            }
            name = new char[16];
            sprintf(name, "%s %d", "�������", id); //������ � name ������� %�����_�������%
        };
        Matrix(int _i, int _j): i(_i), j(_j){ //����������� �� �������� �������
            if(i <= 0 && j <= 0) throw 1; //�������� �� ������������� ������� (�� �������� ������� � �� � �������������� ���������)
            id = count();            
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] = 0; //�� ��������� �������� ���������������� ������
                }
            }
            name = new char[16];
            sprintf(name, "%s %d", "�������", id);
        };
        Matrix(int _i, int _j, UT **arr): i(_i), j(_j){ //����������� �� �������� ������� � ���������� �������
            if(i <= 0 && j <= 0) throw 1;
            id = count();            
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] = arr[_i][_j];
                }
            }
            name = new char[16];
            sprintf(name, "%s %d", "�������", id);
        };
        Matrix(int _i, int _j, UT *arr): i(_i), j(_j){ //����������� ������� (������� [n][0])
            if(i <= 0) throw 1;
            id = count();
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT;
                matrix[_i] = arr[_i];
            }
            name = new char[16];
            sprintf(name, "%s %d", "�������", id);
        }
        Matrix(const Matrix &obj): i(obj.i), j(obj.j){ //����������� �����������
            id = count();            
            matrix = new UT*[i];
            for(int c = 0; c < i; ++c){
                matrix[c] = new UT[j];
                for(int cj = 0; cj < j; ++cj) matrix[c][cj] = obj.matrix[c][cj];
            }
            name = new char[16];
            sprintf(name, "%s %d", "�������", id);
        };
        ~Matrix(){ //����������
            delete[] matrix;
            std::cout << "_MATRIX_OBJ_" << id << "_SUCCSS_DEL" << std::endl; //��������� �� �������� ������� %�����% �� ������
        };

        UT* operator[](int index){ //���������� ��������� ��������� �� �������, ���������� ��������� �� UT(�������� double*, int*)
            if(index < 0 || index >= i) throw 1; //�������� ������������� �������
            return matrix[index];
        }
        const Matrix<UT> operator+ (const Matrix<UT> &obj) const { //���������� ��������� �������� � ��������
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] + obj.matrix[_i][_j]; //���������� �����������
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator+ (const UT num) const { //���������� ��������� �������� � ������
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] + num; //���������� � ������ �����������
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator- (const UT num) const { //��� � ��� ��������
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] - num;
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator- (const Matrix<UT> &obj) const { //��� � ��� ��������
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] - obj.matrix[_i][_j];
                }
            }
            return Matrix(i, j, arr);
        }
        void operator= (const Matrix<UT> &obj) const { //���������� ��������� ������������
            for(int c = 0; c < i; ++c){
                for(int cj = 0; cj < j; ++cj) matrix[c][cj] = obj.matrix[c][cj]; //����������� ��������� this ������� �������������� �� ������� �������
            }
        }
        const Matrix<UT> operator* (const UT num) const { //���������� ��������� ��������� �� �����
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] * num; //�������?
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator* (const Matrix<UT>& obj){ //���������� ��������� ��������� �� �������
            if(i != obj.j) throw 1; //Big Ehorov is watching you
            UT **arr = new UT*[i];
            for(int row = 0; row < i; ++row){ //���� �� ��������� �����-�������� ��� ���
                arr[row] = new UT[obj.j];
                for(int col = 0; col < obj.j; ++col){ //��� ���� ���� ����������� ���������� 
                    arr[row][col] = 0;
                    for(int k = 0; k < j; ++k){
                        arr[row][col] += matrix[row][k] * obj.matrix[k][col]; //��������� �������
                    }
                }
            }
            return Matrix(i, obj.j, arr); //������� ������ �� ������������� �������
        }
        const Matrix<UT> operator/ (const UT num) const { //� ����������� �������� ��� ����� ��� ���
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] / num;
                }
            }
            return Matrix(i, j, arr);
        }
        void operator+= (const Matrix<UT> &obj) const { //���������� ��������� �������������, � �� ��� �� ����������
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){ //������ ���� ����� ��� ����� ���������� ��� �������, ������ ��� ����� ���������� � ����� �����
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] += obj.matrix[_i][_j];
                }
            }
        }
        void operator+= (const UT num) const { //����������
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] += num;
                }
            }
        }
        void operator-= (const Matrix<UT> &obj) const { //����������� ������
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] -= obj.matrix[_i][_j];
                }
            }
        }
        void operator-= (const UT num) const { //��������� ����, �� ����� � ����
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] -= num;
                }
            }
        }
        void operator*= (const UT num) const { //���
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] *= obj.matrix[_i][_j];
                }
            }
        }
        
        void operator/= (const UT num) const { //�����
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] /= obj.matrix[_i][_j];
                }
            }
        }
        bool operator== (const Matrix<UT> &obj){ //���������� ��������� ���������
            if(i != obj.i || j != obj.j) return false; //���� �� ��������� �������, �� ������ ��������, ��� ������� �� ���������
            bool result = true;
            for(int _i = 0; _i < i; ++_i){
                if(!result) break; //���� ���� ���� ���� ������� �� �������� � ��� ��������������� - ����� ���� �����, ���������� 0
                for(int _j = 0; _j < j; ++_j){
                    result = matrix[_i][_j] == obj.matrix[_i][_j]; //�� ��� ����������, �� ����� �������� �������������
                }
            }
            return result;
        }

        const Matrix<UT> Power(int n){ //���������� � ������� �������
            if(i != j) throw 1; //��� �� ����� ������������ ������� ��������� � ������� ������
            Matrix obj(*this);
            for(int c = 0; c < n - 1; ++c){
                obj = obj * obj; //�������� ����� ����� ��� � ����
            }
            return Matrix(obj);
        }

        char* GetName() const { return name; } //������* �����������() ������������ { ������� ���; }
        UT RowSumm(int _i){ //����� ��������� ������ ����� _i
            UT result = 0;
            for(int _j = 0; _j < j; ++_j){
                result += matrix[_i][_j];
            }
            return result;
        }
        UT ColSumm(int _j){ //����� ��������� ������� ����� _i
            UT result = 0;
            for(int _i = 0; _i < i; ++_i){
                result += matrix[_i][_j];
            }
            return result;            
        }
        UT Biggest(){ //���������� ������� � �������
            UT result = 0;
            for(int I = 0; I < i; ++I){
                for(int J = 0; J < j; ++J){
                    if(result > matrix[I][J]) result = matrix[I][J];
                }
            }
            return result;            
        }
        UT Smallest(){ //���������� ������� � �������
            UT result = matrix[0][0];
            for(int I = 0; I < i; ++I){
                for(int J = 0; J < j; ++J){
                    if(result < matrix[I][J]) result = matrix[I][J];
                }
            }
            return result;
        }
        UT ColMin(int index){ //���������� ������� � �������
            UT buff = matrix[0][index];
            for(int _i = 0; _i < i; ++_i){
                if(buff > matrix[_i][index]) buff = matrix[_i][index];
            }
            return buff;
        }
        UT ColMax(int index){ //���������� ������� � �������
            UT buff = matrix[0][index];
            for(int _i = 0; _i < i; ++_i){
                if(buff < matrix[_i][index]) buff = matrix[_i][index];
            }
            return buff;
        }
        int GetRowNumber() const { //�������� ���������� �����
            return j;
        }
        int GetColNumber() const { //��������
            return i;
        }
        void GetMinVector(UT* vector){ //�������� � vector ������ �� ����������� �������� ��������
            for(int I = 0; I < i; ++I){
                vector[I] = ColMin(I);
            }
        }
        UT Get(int _i, int _j) const { return matrix[_i][_j]; } //��������� �������� [i][j]
        const Matrix<UT> GetSubMatrix(int rows, int cols){
            UT **arr = new UT*[rows];
            for(int I = 0; I < rows; ++I){
                arr[I] = new UT[cols];
                for(int J = 0; J < cols; ++J){
                    arr[I][J] = matrix[I][J];
                }
            }
            return Matrix(rows, cols, arr);
        }
        void Set(int _i, int _j, int value) { matrix[_i][_j] = value; } //������������ �������� [i][j] value
        void Set(int value) { //������������ ������� �������� value
            for(int row = 0; row < i; ++row){
                for(int col = 0; col < j; ++col){
                    matrix[row][col] = value;
                }
            }
        }
};

template <typename UT>
std::ostream& operator<< (std::ostream& out, const Matrix<UT> &obj){ //���������� ��������� ������
    out << obj.GetName() << endl;
    for(int i = 0; i < obj.GetColNumber(); ++i){
        out << "| ";
        for(int j = 0; j < obj.GetRowNumber(); ++j){
            out << obj.Get(i, j) << " ";
        }
        out << "|\n";
    }
    return out;
}