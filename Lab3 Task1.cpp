#include<iostream>
using namespace std;
class Course {
protected:
	virtual void duration() = 0;

};
class OnlineCourse:protected Course {
private:
	int weeks;
	int hoursperweek;
public:
	OnlineCourse(int w, int hpw) {
		weeks = w;
		hoursperweek = hpw;

	}
	int area() {
		return weeks * hoursperweek;
	}
	void duration() override {
		cout << "The duration of online classes is " << area() << endl;
	}
};
class OfflineCourse :protected Course {
private:
	int months;
	int hoursperday;
public:
	OfflineCourse(int m, int hpd) {
		months = m;
		hoursperday = hpd;

	}
	int area() {
		return months * hoursperday;
	}
	void duration() override {
		cout << "The duration of online classes is " << area() << endl;
	}
};
int main() {
	OnlineCourse O1(4, 12);
	O1.duration();
	OfflineCourse O2(16, 8);
		O2.duration();
		return 0;

	
}