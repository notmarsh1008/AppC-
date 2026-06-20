#include <iostream>
using namespace std;
class Time {
    int hours;
    int minutes;
    int seconds;

    int toAllSeconds() const {

        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    Time() {
        hours = minutes = seconds = 0;
   }

    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    explicit Time(int totalSeconds) {
        if (totalSeconds < 0) totalSeconds = 0;
        this->hours = totalSeconds / 3600;
        this->minutes = (totalSeconds / 60) % 60;
        this->seconds = totalSeconds % 60;
    }

    void Print() const {
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << ":";
        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }

    void IncrementSecond() {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
            if (minutes >= 60) {
                minutes = 0;
                hours++;
            }
        }
    }

    Time operator+(const Time& other) const {
        return Time(this->toAllSeconds() + other.toAllSeconds());
    }
    Time operator-(const Time& other) const {
        return Time(this->toAllSeconds() - other.toAllSeconds());
    }

    Time operator*(const Time& other) const {
        return Time(this->toAllSeconds() * other.toAllSeconds());
    }

    Time operator/(const Time& other) const {
        int otherSec = other.toAllSeconds();
        if (otherSec == 0) return Time(0);
        return Time(this->toAllSeconds() / otherSec);
    }

    bool operator<(const Time& other) const {
        return this->toAllSeconds() < other.toAllSeconds();
    }
    bool operator>(const Time& other) const {
        return this->toAllSeconds() > other.toAllSeconds();
    }
    bool operator<=(const Time& other) const {
        return this->toAllSeconds() <= other.toAllSeconds();
    }
    bool operator>=(const Time& other) const {
        return this->toAllSeconds() >= other.toAllSeconds();
    }
    bool operator==(const Time& other) const {
        return this->toAllSeconds() == other.toAllSeconds();
    }
    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

};

int main() {
    int h, m, s;
    int secInput;
    cout << "Enter Time 1 (3 razi): ";
    cin >> h >> m >> s;
    Time t1(h, m, s);
    cout << "Enter Time 2 (3 razi): ";
    cin >> h >> m >> s;
    Time t2(h, m, s);
    cout << "Enter total seconds for Time 3: ";
    cin >> secInput;
    Time t3(secInput);
    cout << "\nYour times:" << endl;
    cout << "Time 1: "; t1.Print();
    cout << "Time 2: "; t2.Print();
    cout << "Time 3: "; t3.Print();
    cout << "\n Time 1 by 1 second" << endl;
    t1.IncrementSecond();
    cout << "Time 1 now: "; t1.Print();
    cout << "\nOperations with Time 1 and Time 2:" << endl;
    Time resAdd = t1 + t2;
    cout << "Time 1 + Time 2 = "; resAdd.Print();
    Time resSub = t1 - t2;
    cout << "Time 1 - Time 2 = "; resSub.Print();
    cout << "\nComparisons:" << endl;
    if (t1 > t2) {
        cout << "Time 1 is greater than Time 2" << endl;
    }

    else if (t1 < t2) {
        cout << "Time 1 is less than Time 2" << endl;
    }

    else {
        cout << "Time 1 is equal to Time 2" << endl;
    }

    return 0;
}
