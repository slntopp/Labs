#include <iostream>
using namespace std;

#include "reportform.h"
#include "validation.h"
#include "exam.h"
#include "diffvalidation.h"
#include "stateexam.h"


int main(){

    Exam obj(4);
    StateExam obj1(4);
    cout << obj.YN() << endl;
    cout << obj1.YN() << endl;

    return 0;
}