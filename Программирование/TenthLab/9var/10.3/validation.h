class Validation : public ReportForm {
    public:
        Validation(const char* _name = "�����", bool _result = false) : ReportForm(_name, _result) {}
        virtual const char* Specs() { return "�����, ���������: ���� �����"; }
        virtual void PrintData() { cout << Specs() << " - " << YN() << endl;}
};