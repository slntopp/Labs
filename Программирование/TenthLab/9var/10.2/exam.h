class Exam : public Validation {
    protected:
        static const int def_border = 4;
        int mark;
    public:
        Exam(int _mark = 1, const char* _name = "Экзамен", const int border = def_border){
            mark = _mark;
            int i = 0;
            while(_name[i++] != '\0');
            name = new char[i];
            for(int j = 0; j < i; ++j) name[j] = _name[j];
            result = (mark >= border);
        }
        int GetMark() { return mark; }
};