#include <iostream>
#include <stdio.h>

using namespace std;

char *bin(char*);
bool numcompare(char);

int main(){
	char *string = new char;
	cout << "Type here your string: ";
	gets(string);
	int i = 0;
	while(string[i] != '.'){
		++i;
	}
	bool num = false;
	do{
		int k = 0;
		char *currnum = new char;
		while(numcompare(string[i])){
			currnum[k] = string[i];
			++k, ++i;
		}
		if(numcompare(string[i - k])){
			cout << currnum << " - " << bin(currnum) << endl;
		}
		delete []currnum;
	} while(string[i] != '.');

	cout << string << endl;
	return 0;
}

char *bin(char* a){
	int num = int(*a);
	char *res = new char;
    do {
        res = ('0' + (num % 2)) + res;
        num /= 2;
    } while (num > 0);
    return res;
}

bool numcompare(char curnum){
	bool res = false;
	char *num_arr = new char;

	for(int i = 0; i < 10; ++i){
		num_arr[i] = char(i);
		if(curnum == num_arr[i]){
			res = true;
			break;
		}
	}
	cout << "num_arr is: " << num_arr << endl;
	return res;
}