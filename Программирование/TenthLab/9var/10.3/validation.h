class Validation : public ReportForm {
    public:
        Validation(const char* _name = "Зачет", bool _result = false) : ReportForm(_name, _result) {}
        virtual const char* Specs() { return "Зачет, Результат: Факт Сдачи"; }
        virtual void PrintData() { cout << Specs() << " - " << YN() << endl;}
};