#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int n;
	cout << "Type n: ";
	cin >> n;
	if (n <= 0) {
		cout << "n should be greater then 0" << endl;
		main();
		return 1;
	}

	
	int *m_arr = new int[n];
	srand(time(0));
	for(int i = 0; i < n; ++i){
		cout << "Generating next array[] member... It's - ";
		m_arr[i] = 100 - rand()%201;
		cout << m_arr[i] << endl;
	}
	int k = 0;
	cout << "Appending numbers lower than 0..." << endl;
	for(int j = 0; j < n; ++j){
		if(m_arr[j] < 0){
			m_arr[n + k] = m_arr[j];
			cout << "\tAppended " << m_arr[j] << endl;
			++k;
		}
	}
	cout << "Appending numbers equal to 0..." << endl;
	for(int j = 0; j < n; ++j){
		if(m_arr[j] == 0){
			m_arr[n + k] = m_arr[j];
			cout << "\tAppended " << m_arr[j] << endl;
			++k;
		}
	}
	cout << "Appending numbers greater than 0..." << endl;
	for(int j = 0; j < n; ++j){
		if(m_arr[j] > 0){
			m_arr[n + k] = m_arr[j];
			cout << "\tAppended " << m_arr[j] << endl;
			++k;
		}
	}

	cout << "Resulting array here:" << endl;
	cout << "[ ";
	for(int l = n; l < n + k - 1; ++l){
		cout << m_arr[l] << ",\t";
		if(!(l % 8) & l != 0) cout << endl;
	}
	cout << m_arr[n + k - 1] << " ]" << endl;
	cout << "_____________________________________" << endl;

	return 0;
}