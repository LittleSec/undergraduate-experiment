#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include"Observer.h"
#include"Subject.h"

class Subject;

// 应届大学毕业生
class Student:public Observer {
public:
    Student(const string name, Subject *subject); // 在求职中心登记
    void answerPhone(const string &message);
    ~Student(){};
};

#endif // STUDENT_H_INCLUDED
