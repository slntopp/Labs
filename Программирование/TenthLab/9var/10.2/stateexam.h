class StateExam : public Exam {
    protected:
        static const int def_border = 8;
    public:
        StateExam(int _mark = 1, const char* _name = "Гос. Экзамен", int border = def_border) : Exam(_mark, _name, border) {}
};