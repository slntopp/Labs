struct info {
    char* fio;
    int nomer;
    int sum;
    double proc;
};

class Bank {
    private:
        char* name;
        char* ceo;
        info* information;
        int inf_length;
    public:
        Bank(){
            name = "unknown";
            ceo = "unknown";
            information = new info;
            information[0].fio = "unknown";
            information[0].nomer = 0;
            information[0].sum = 0;
            information[0].proc = 0;
            inf_length = 1;
        }
        Bank(char* name, char* direct, int clients = 1): inf_length(clients) {
            this -> name = name;
            this -> ceo = direct;
            information = new info[clients];
            for(int i = 0; i < clients; ++i){
                this -> information[i].nomer = i;
                this -> information[i].sum = 100;
                this -> information[i].proc = 0.34;
            }
        }
        char* GetName() const { return name; }
        char* GetCEO() const { return ceo; }
        int GetAmount() const { return inf_length; }
        double GetBalance() const {
            double result = 0;
            for(int i = 0; i < this -> inf_length; ++i) result += (this -> information[i].sum * (this -> information[i].proc + 1));    
            return result;
        }
        bool operator< (const Bank &obj){
            double first = GetBalance(), second = obj.GetBalance();
            return first < second;
        }
        bool operator> (const Bank &obj){
            double first = GetBalance(), second = obj.GetBalance();
            return first > second;
        }
        bool operator== (const Bank &obj){
            double first = GetBalance(), second = obj.GetBalance();            
            return first == second;
        }
        int operator[] (int index){
            return this -> information[index].sum;
        }
        void operator+= (int _sum){
            for(int i = 0; i < inf_length; ++i){
                this -> information[i].sum += _sum;
            }
        }
};

ostream& operator<< (ostream& out, const Bank &obj){
    out << "Банк \"" << obj.GetName() << "\": \n\tБаланс - " << obj.GetBalance() << "\n\tКол-во клиентов - " << obj.GetAmount() << "\n\tГен.Директор - " << obj.GetCEO() << endl;
    return out;
}