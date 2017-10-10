class Exam : public Validation {
    protected:
        static const int def_border = 4;
        int mark;
    public:
        Exam(int _mark = 1, const char* _name = "Ёкзамен", const int border = def_border){
            mark = _mark;
            int i = 0;
            while(_name[i++] != '\0');
            name = new char[i];
            for(int j = 0; j < i; ++j) name[j] = _name[j];
            result = (mark >= border);
        }
        int GetMark() { return mark; }
        const char* Specs(){ return "Ёкзамен, –езультат: оценка, ѕоложительный результат: от 4"; }
        virtual void EnterData(){ cout << "¬ведите результат(1..10): "; cin >> mark; result = (mark >= def_border); if(!result) throw PassException("UnPassed_Stage_Exception");}
        // virtual void PrintData(){ cout << Specs() << " - " << YN() << endl; }
        virtual void ChangeData(){ EnterData(); PrintData(); }
};