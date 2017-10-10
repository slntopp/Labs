class Validation : public ReportForm<bool> {
    public:
        Validation(const char* _name = "Зачет", bool _result = false) : ReportForm<bool>(_name, _result) {}
};