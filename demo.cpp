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
    mg90s.setAngle(0); // 相当于 0 度，500us
    std::this_thread::sleep_for(std::chrono::seconds(2));

    cout << "2" << endl;
    mg90s.setAngle(90); // 中间位置，1500us
    std::this_thread::sleep_for(std::chrono::seconds(2));

    cout << "3" << endl;
    mg90s.setAngle(180); // 最大角度，2500us
    std::this_thread::sleep_for(std::chrono::seconds(2));

    cout << "Motor moved" << endl;

    return 0;
}