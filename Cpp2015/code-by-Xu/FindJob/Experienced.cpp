#include "Experienced.h"

Experienced::Experienced(const string &name, Subject *subject) : Observer(name) {
	subject->addObserver(this);
}

void Experienced::answerPhone(const string &message) {
	cout << "我叫" << name << "，我有工作经验，待遇要好。我收到了招聘信息：" << message << endl;
}
