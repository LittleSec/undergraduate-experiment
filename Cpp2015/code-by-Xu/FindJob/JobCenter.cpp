#include "JobCenter.h"

JobCenter::JobCenter() {
	cout << "求职中心成立了" << endl << endl;
	statusChanged = false;
	numObserver = 0;
	for (int i = 0; i < 100; i++)
		list[i] = NULL;
}

JobCenter::~JobCenter()  {
	cout << "求职中心关闭了" << endl;
}

void JobCenter::addObserver(Observer *pObserver) {
	if (!pObserver)
		return;
	list[numObserver++] = pObserver;
}

void JobCenter::publishMessage(const string &message) {
	if (this->message == message) {
		statusChanged = false;
		cout << "该信息已经发布过了" << endl;
	} else {
		this->message = message;
		statusChanged = true;
		cout << "发布招聘信息：" << message << endl << endl;
	}
}

void JobCenter::notifyObservers() {
	if (statusChanged) {
		cout << "通知所有求职者 ..." << endl;

		for (int i = 0; i < numObserver; i++) {
			list[i]->answerPhone(message);
		}
	}
}
