#ifndef MG90S_SETTING_H
#define MG90S_SETTING_H

#include "pwm.h"

class MG90S
{
    public:
    
    void start_mg90s()
    {
        pwm.start_pwm(channel,frequency,0, chip);
    }

    void setAngle(int angle)
    {
        int duty_ns = angleToDutyNs(angle);

        pwm.setDutyCycle(duty_ns);
    }

    private:
    PWM pwm;
    
    const int channel = 3;
    const int frequency = 50;
    const int chip = 0;

    int angleToDutyNs(int angle)
    {
        return 500000 + angle * (2000000/180);
    }
};

#endif