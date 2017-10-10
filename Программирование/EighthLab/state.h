class State {
    private:
        char* name;
        double population, square;
    public:
        State(){
            name = "EMPTY_STATE";
            population = square = 0;
        }
        State(const char* _name, double _population = 0, double _square = 0): population(_population), square(_square){
            name = new char[strlen(_name + 1)];
            strcpy(name, _name);
        }
        State(const State &obj): population(obj.population), square(obj.square){
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name);
        }
        State operator+ (const State &obj){
            return State(name, population + obj.population, square + obj.square);
        }
        ~State(){ delete[] name; }
        const char* GetName() const { return name; }
        double GetPopulation() const { return population; }
        double GetSquare() const { return square; }
}

std::ostream& operator<< (std::ostream& out, const State &obj){
    out << "Государство " << obj.GetName() << ":\n Население - " << obj.GetPopulation() << "чел.\n Площадь - " << obj.GetSquare() << "кв. км." << endl; 
    return out;
}