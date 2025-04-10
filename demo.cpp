#include "MG90S_setting.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {
    PWM pwm;
    pwm.start_pwm(2, 50, 7.5, 2); // chip=2, channel=2
    std::this_thread::sleep_for(std::chrono::seconds(2));

    pwm.setDutyCycle(0);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pwm.setDutyCycle(15);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
