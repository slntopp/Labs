template<typename UT> //Шаблонная функция перегрузки оператора вывода для вектора
std::ostream& operator<<(std::ostream& out, const std::vector<UT> &obj){ //Чтобы выводила вектор с элементами любого типа
    for(int i = 0; i < obj.size(); ++i) out << obj[i] << " "; //Вывод элементов через пробел
    return out;
}
template<typename UT> //Шаблонная функция перегрузки оператора ввода для вектора
std::istream& operator>>(std::istream& in, std::vector<UT> &obj){
    for(int i = 0; i < obj.size(); ++i){ in >> obj[i]; } //Так как мы сразу выделили под вектор len элементов, size отработает правильно
    return in;
}