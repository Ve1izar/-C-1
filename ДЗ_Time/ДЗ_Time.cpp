#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Time {
private:
	int hours;
	int minutes;
	int seconds;

	void normalize() {
		int totalSeconds = hours * 3600 + minutes * 60 + seconds;
		if (totalSeconds < 0) totalSeconds = 0;

		hours = totalSeconds / 3600;
		minutes = (totalSeconds / 60) % 60;
		seconds = totalSeconds % 60;
	}

public:
	Time() : hours(0), minutes(0), seconds(0) {}

	explicit Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
		normalize();
	}

	explicit Time(int totalSeconds) {
		hours = totalSeconds / 3600;
		minutes = (totalSeconds / 60) % 60;
		seconds = totalSeconds % 60;
	}

	int toSeconds() const {
		return hours * 3600 + minutes * 60 + seconds;
	}

	void GetTime() const {
		cout << "Час: " << hours << " годин, " << minutes << " хвилин, " << seconds << " секунд\n";
	}

	void SetTime(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
		if (seconds >= 60) {
			minutes += seconds / 60;
			seconds %= 60;
		}
		if (minutes >= 60) {
			hours += minutes / 60;
			minutes %= 60;
		}
	}

	void SetSeconds(int s) {
		seconds = s;
		if (seconds >= 60) {
			minutes += seconds / 60;
			seconds %= 60;
		}
		if (minutes >= 60) {
			hours += minutes / 60;
			minutes %= 60;
		}
	}

	void SetMinutes(int m) {
		minutes = m;
		if (minutes >= 60) {
			hours += minutes / 60;
			minutes %= 60;
		}
	}

	void SetHours(int h) {
		hours = h;
		if (hours < 0) hours = 0;
	}

	int GetHours() const {
		return hours;
	}

	int GetMinutes() const {
		return minutes;
	}

	int GetSeconds() const {
		return seconds;
	}

	void PrintTime() const {
		cout << (hours < 10 ? "0" : "") << (hours < 0 ? "0" : to_string(hours)) << ":" << (minutes < 10 ? "0" : "") << (minutes < 0 ? "0" : to_string(minutes)) << ":" << (seconds < 10 ? "0" : "") << (seconds < 0 ? "0" : to_string(seconds)) << endl;
	}

	void AddSec() {
		seconds++;
		normalize();
	}

	Time operator +(const Time& other) const {
		return Time(toSeconds() + other.toSeconds());
	}

	Time operator -(const Time& other) const {
		return Time(toSeconds() - other.toSeconds());
	}

	Time operator *(const Time& other) const {
		return Time(toSeconds() / other.toSeconds());
	}

	Time operator /(const Time& other) const {
		return Time(toSeconds() / other.toSeconds());
	}

	bool operator ==(const Time& other) const {
		return toSeconds() == other.toSeconds();
	}

	bool operator <(const Time& other) const {
		return toSeconds() < other.toSeconds();
	}

	bool operator >(const Time& other) const {
		return toSeconds() > other.toSeconds();
	}

	bool operator <=(const Time& other) const {
		return toSeconds() <= other.toSeconds();
	}

	bool operator >=(const Time& other) const {
		return toSeconds() >= other.toSeconds();
	}

	bool operator !=(const Time& other) const {
		return toSeconds() != other.toSeconds();
	}

};


int main()
{
	Time t1;
	Time t2(1, 30, 45);
	Time t3 = Time(5555);

	t1.PrintTime();
	t2.PrintTime();
	t3.PrintTime();

	t3.PrintTime();
	t3.PrintTime();

	Time t4 = t2 + t3;
	t4.PrintTime();

	Time t5 = t2 - t3;
	t5.PrintTime();

	Time t6 = t2 * t3;
	t6.PrintTime();

	Time t7 = t2 / t3;
	t7.PrintTime();

	cout << "t2 > t3: " << (t2 > t3) << endl;
	cout << "t2 == t2: " << (t2 == t2) << endl;
	cout << "t2 != t3: " << (t2 != t3) << endl;
	cout << "t2 < t3: " << (t2 < t3) << endl;
	cout << "t2 <= t3: " << (t5 <= t6) << endl;
	cout << "t2 >= t3: " << (t3 >= t4) << endl;

	return 0;
}

