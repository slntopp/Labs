class StateExam : public Exam {
    protected:
        static const int def_border = 8;
    public:
        StateExam(int _mark = 1, const char* _name = "Гос. Экзамен", int border = def_border) : Exam(_mark, _name, border) {}
        const char* Specs(){ return "Гос. Экзамен, Результат: оценка, Положительный результат: от 8"; }
        virtual void EnterData(){ cout << "Введите результат(1..10): "; cin >> mark; result = (mark >= def_border); if(!result) throw PassException("UnPassed_Stage_Exception");}
};