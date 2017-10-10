class PassException : std::exception {
    private:
        std::string whatStr;
    public:
        PassException(std::string &&whatStr) noexcept : whatStr(std::move(whatStr)) { };
        PassException(const std::string &whatStr) noexcept : whatStr(whatStr) { };
        ~PassException() noexcept = default;
        
        const char* what() const noexcept override {
            return whatStr.c_str();
        }
};
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
        virtual void EnterData(){ cout << "Введите результат(bool): "; cin >> result; if(!result) throw PassException("UnPassed_Stage_Exception");}
        virtual void PrintData(){ cout << GetName() << " - " << YN() << endl; }
        virtual void ChangeData(){ EnterData(); PrintData(); }
};