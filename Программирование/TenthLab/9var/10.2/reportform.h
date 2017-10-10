template <typename UT>
class ReportForm {
    protected:
        char* name;
        bool result;
    public:
        ReportForm(const char* _name = "Отчет", bool _result = false): result(_result){
            int i = 0;
            while(_name[i++] != '\0');
            name = new char[i];
            for(int j = 0; j < i; ++j) name[j] = _name[j];
        }
        char* GetName() { return name; }
        bool GetResult() { return result; }
        const char* YN() { return result ? "Сдан" : "Не сдан"; }
};