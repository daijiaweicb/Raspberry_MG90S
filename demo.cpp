#include "MG90S_setting.h"
#include <chrono>
#include <thread>

using namespace std;

#include "pwm.h"
#include <chrono>
#include <thread>

int main() {
    PWM pwm;
    pwm.start_pwm(1, 50, 7.5, 0); // GPIO18, 50Hz, 中位
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pwm.setDutyCycle(5);          // 5% duty = 左边
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pwm.setDutyCycle(10);         // 10% duty = 右边
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}
