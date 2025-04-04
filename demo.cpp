#include "MG90S_setting.h"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[])
{
    MG90S mg90s;
    mg90s.start_mg90s();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "1" << endl;
    mg90s.pwm.setDutyCycle(0);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "2"<< endl;
    mg90s.pwm.setDutyCycle(7.5);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "3" << endl;

    mg90s.pwm.setDutyCycle(15);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    cout << "Motor move fixed" << endl;

    return 0;
}