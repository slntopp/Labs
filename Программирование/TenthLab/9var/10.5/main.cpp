#include <iostream>
#include <cstring>
// #include "int.h"
#include "basedata.h"
#include "my_iterator.h"
#include "ctime"

std::string BinReverse(std::string in);
const char* toBin(long long n);
int Order(long long x);

int main(){

    unsigned int start_time = clock();

	__int64 limit = 1000000000000;

	BaseData<__int64> base0(2, limit);
	BaseData<__int64> base1(10, limit);

	Iterator<__int64> it0(base0.m_base, base0.m_powers);
	Iterator<__int64> it1(base1.m_base, base1.m_powers);

    int result = 0;

	while (*it0 <= limit) {
		if (*it0 < *it1)
			++it0;
		else if (*it0 > *it1)
			++it1;
		else {
    		if(result < 20 && *it0 > 10000){ std::cout << *it0 << " - " << toBin(*it1) << std::endl; }
			++it0;
			++it1;
            if(*it0 > 10000) ++result;
		}
	}

    std::cout << "Итоговое количество палиндромов: " << result << std::endl;
    std::cout << "Время работа: " << (clock() - start_time) / 1000.0 << std::endl;


	return 0;
}

const char* toBin(long long n){
    char* result = new char[65];
    int i = 0;
    do {
       result[i++] = ('0' + (n % 2));
       n = n / 2;
    } while (n > 0);
    result[i] = '\0';
    return result;
}

int Order(long long x){
    int order = 1;
    while(x / int(pow(10, order)) != 0) ++order;
    return order;
}

std::string BinReverse(std::string in){
    std::string result;
    for(int i = in.length() - 1; i >= 0; --i){
        result.push_back(in[i]);
    }
    return result;
}