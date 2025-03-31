#include "MG90S_setting.h"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    MG90S mg90s;
    mg90s.start_mg90s();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    mg90s.setAngle(0);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    mg90s.setAngle(90);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    mg90s.setAngle(180);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}