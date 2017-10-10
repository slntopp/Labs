#include <iostream>
using namespace std;

#include "reportform.h"
#include "validation.h"
#include "exam.h"
#include "diffvalidation.h"
#include "stateexam.h"

void input(ReportForm *obj);

int main(){

    ReportForm *array[3];
    array[0] = new Validation;
    array[1] = new Exam;
    array[2] = new StateExam;

    for(int i = 0; i < 3; ++i) input(array[i]);

    return 0;
}

void input(ReportForm *obj){
    cout << obj -> GetName() << ":" << endl;
    int i = 1;
    Peresdacha:
    try {
        obj -> ChangeData();
    } catch(const PassException& e){
        if(i == 3) goto Otchislenie;
        cout << "На пересдачу!" << endl;
        ++i;
        goto Peresdacha;
    }
    return;
    Otchislenie:
        cout << "Отчислен!" << endl;
        exit(1);
}