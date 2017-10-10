#pragma once

/*---M--E--T--H--O--D--S-----------------------------------
void Set(int i, int j, int value) - присваивание элементу [i][j] значения value
void Set(int value) - присваивание каждому элементу матрицы значения value
UT Get(int i, int j) - получение значения элемента [i][j]
void GetMinVector(UT* vector) - запись в массив vector вектора из минимальных значений столбцов
int GetColNumber() - получение количества столбцов
int GetRowNumber() - получение количества строк
UT ColMax(int j) - получение максимального значения столбца j
UT ColMin(int j) - получение минимального значения столбца j
UT Biggest() - получение максимального значения матрицы
UT Smallest() - получение минимального значение матрицы
UT RowSumm(int i) - получение суммы элементов строки i
UT ColSumm(int j) - получение суммы элементов столбца j
char* GetName() - получение имени матрицы
Matrix Power(int n) - возведение матрицы в степень n
----------------------------------------------------*/


template <typename UT = double> //Тип по умолчанию double, для этого нужно инициализировать как Matrix <>obj;
class Matrix {
    private:
        UT** matrix;
        int i, j, id;
        static inline int count() { static int _storage = 0; return _storage++; } //Счетчик объектов
        char *name;
    public:
        Matrix(){ //Контруктор без параметров
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
            sprintf(name, "%s %d", "Матрица", id); //Запись в name Матрица %номер_объекта%
        };
        Matrix(int _i, int _j): i(_i), j(_j){ //Конструктор по размерам матрицы
            if(i <= 0 && j <= 0) throw 1; //Проверка на существование матрицы (не нулевого размера и не с отрицательными размерами)
            id = count();            
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] = 0; //По умолчанию элементы инициализируются нулями
                }
            }
            name = new char[16];
            sprintf(name, "%s %d", "Матрица", id);
        };
        Matrix(int _i, int _j, UT **arr): i(_i), j(_j){ //Конструктор по размерам матрицы и двумерному массиву
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
            sprintf(name, "%s %d", "Матрица", id);
        };
        Matrix(int _i, int _j, UT *arr): i(_i), j(_j){ //Конструктор вектора (матрицы [n][0])
            if(i <= 0) throw 1;
            id = count();
            matrix = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                matrix[_i] = new UT;
                matrix[_i] = arr[_i];
            }
            name = new char[16];
            sprintf(name, "%s %d", "Матрица", id);
        }
        Matrix(const Matrix &obj): i(obj.i), j(obj.j){ //Конструктор копирования
            id = count();            
            matrix = new UT*[i];
            for(int c = 0; c < i; ++c){
                matrix[c] = new UT[j];
                for(int cj = 0; cj < j; ++cj) matrix[c][cj] = obj.matrix[c][cj];
            }
            name = new char[16];
            sprintf(name, "%s %d", "Матрица", id);
        };
        ~Matrix(){ //Деструктор
            delete[] matrix;
            std::cout << "_MATRIX_OBJ_" << id << "_SUCCSS_DEL" << std::endl; //Сообщение об удалении объекта %номер% из памяти
        };

        UT* operator[](int index){ //Перегрузка оператора обращения по индексу, возвращает указатель на UT(например double*, int*)
            if(index < 0 || index >= i) throw 1; //Проверка существования индекса
            return matrix[index];
        }
        const Matrix<UT> operator+ (const Matrix<UT> &obj) const { //Перегрузка оператора сложения с матрицей
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] + obj.matrix[_i][_j]; //Складываем поэлементно
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator+ (const UT num) const { //Перегрузка оператора сложения с числом
            if(i != obj.i || j != obj.j) throw 1;
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] + num; //Складываем с числом поэлементно
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator- (const UT num) const { //Как и для сложения
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
        const Matrix<UT> operator- (const Matrix<UT> &obj) const { //Как и для сложения
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
        void operator= (const Matrix<UT> &obj) const { //Перегрузка оператора присваивания
            for(int c = 0; c < i; ++c){
                for(int cj = 0; cj < j; ++cj) matrix[c][cj] = obj.matrix[c][cj]; //Присваиваем элементам this объекта соответсвующие во входном объекте
            }
        }
        const Matrix<UT> operator* (const UT num) const { //Перегрузка оператора умножения на число
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] * num; //Допрешь?
                }
            }
            return Matrix(i, j, arr);
        }
        const Matrix<UT> operator* (const Matrix<UT>& obj){ //Перегрузка оператора умножения на матрицу
            if(i != obj.j) throw 1; //Big Ehorov is watching you
            UT **arr = new UT*[i];
            for(int row = 0; row < i; ++row){ //Идем по элементам строк-столбцов хуе мое
                arr[row] = new UT[obj.j];
                for(int col = 0; col < obj.j; ++col){ //Это туда сюда перемножаем складываем 
                    arr[row][col] = 0;
                    for(int k = 0; k < j; ++k){
                        arr[row][col] += matrix[row][k] * obj.matrix[k][col]; //Приюавили малайца
                    }
                }
            }
            return Matrix(i, obj.j, arr); //Вернули объект из получившегося массива
        }
        const Matrix<UT> operator/ (const UT num) const { //Я отказываюсь пояснять это говно еще раз
            UT **arr = new UT*[i];
            for(int _i = 0; _i < i; ++_i){
                arr[_i] = new UT[j];
                for(int _j = 0; _j < j; ++_j){
                    arr[_i][_j] = matrix[_i][_j] / num;
                }
            }
            return Matrix(i, j, arr);
        }
        void operator+= (const Matrix<UT> &obj) const { //Перегрузка оператора сложсваивания, я хз как он называется
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){ //Короче тоже самое как когда складывали две матрицы, только тут сразу записываем в левую часть
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] += obj.matrix[_i][_j];
                }
            }
        }
        void operator+= (const UT num) const { //АНАЛогично
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] += num;
                }
            }
        }
        void operator-= (const Matrix<UT> &obj) const { //Аналогичнее некуда
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] -= obj.matrix[_i][_j];
                }
            }
        }
        void operator-= (const UT num) const { //Оказалось есть, но пошел в жопу
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] -= num;
                }
            }
        }
        void operator*= (const UT num) const { //фак
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] *= obj.matrix[_i][_j];
                }
            }
        }
        
        void operator/= (const UT num) const { //ебана
            if(i != obj.i || j != obj.j) throw 1;
            for(int _i = 0; _i < i; ++_i){
                for(int _j = 0; _j < j; ++_j){
                    matrix[_i][_j] /= obj.matrix[_i][_j];
                }
            }
        }
        bool operator== (const Matrix<UT> &obj){ //Перегрузка оператора равенства
            if(i != obj.i || j != obj.j) return false; //Если не совпадают размеры, то видимо очевидно, что матрицы не одинаковы
            bool result = true;
            for(int _i = 0; _i < i; ++_i){
                if(!result) break; //Если хоть один сука элемент не совпадет с ему соответствующим - нахер этот цикол, возвращаем 0
                for(int _j = 0; _j < j; ++_j){
                    result = matrix[_i][_j] == obj.matrix[_i][_j]; //Ну тут сравниваем, не люблю линейные повествования
                }
            }
            return result;
        }

        const Matrix<UT> Power(int n){ //Возведение в степень матрицы
            if(i != j) throw 1; //Как мы знаем неквадратные матрицы возводить в степень нельзя
            Matrix obj(*this);
            for(int c = 0; c < n - 1; ++c){
                obj = obj * obj; //Умножаем многа многа раз и тада
            }
            return Matrix(obj);
        }

        char* GetName() const { return name; } //символ* ПолучитьИмя() стабильность { вернуть имя; }
        UT RowSumm(int _i){ //Сумма элементов строки номер _i
            UT result = 0;
            for(int _j = 0; _j < j; ++_j){
                result += matrix[_i][_j];
            }
            return result;
        }
        UT ColSumm(int _j){ //Сумма элементов столбца номер _i
            UT result = 0;
            for(int _i = 0; _i < i; ++_i){
                result += matrix[_i][_j];
            }
            return result;            
        }
        UT Biggest(){ //Наибольший элемент в матрице
            UT result = 0;
            for(int I = 0; I < i; ++I){
                for(int J = 0; J < j; ++J){
                    if(result > matrix[I][J]) result = matrix[I][J];
                }
            }
            return result;            
        }
        UT Smallest(){ //Наименьший элемент в матрице
            UT result = matrix[0][0];
            for(int I = 0; I < i; ++I){
                for(int J = 0; J < j; ++J){
                    if(result < matrix[I][J]) result = matrix[I][J];
                }
            }
            return result;
        }
        UT ColMin(int index){ //Наименьший элемент в столбце
            UT buff = matrix[0][index];
            for(int _i = 0; _i < i; ++_i){
                if(buff > matrix[_i][index]) buff = matrix[_i][index];
            }
            return buff;
        }
        UT ColMax(int index){ //Наибольший элемент в столбце
            UT buff = matrix[0][index];
            for(int _i = 0; _i < i; ++_i){
                if(buff < matrix[_i][index]) buff = matrix[_i][index];
            }
            return buff;
        }
        int GetRowNumber() const { //Получить количество строк
            return j;
        }
        int GetColNumber() const { //Столбцоа
            return i;
        }
        void GetMinVector(UT* vector){ //Записать в vector вектор из минимальных значений столбцов
            for(int I = 0; I < i; ++I){
                vector[I] = ColMin(I);
            }
        }
        UT Get(int _i, int _j) const { return matrix[_i][_j]; } //Получение элемента [i][j]
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
        void Set(int _i, int _j, int value) { matrix[_i][_j] = value; } //Присваивание элементу [i][j] value
        void Set(int value) { //Присваивание каждому элементу value
            for(int row = 0; row < i; ++row){
                for(int col = 0; col < j; ++col){
                    matrix[row][col] = value;
                }
            }
        }
};

template <typename UT>
std::ostream& operator<< (std::ostream& out, const Matrix<UT> &obj){ //Перегрузка оператора вывода
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