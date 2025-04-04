#ifndef MG90S_SETTING_H
#define MG90S_SETTING_H

#include "pwm.h"

class MG90S
{
    public:
    PWM pwm;
    void start_mg90s()
    {
        pwm.start_pwm(channel,frequency,7.5, chip);
    }

    void setAngle(int angle)
    {
        int duty_ns = angleToDutyNs(angle);

        pwm.setDutyCycle(duty_ns);
    }

    private:
    
    
    const int channel = 2;
    const int frequency = 50;
    const int chip = 2;

    int angleToDutyNs(int angle)
    {
        return 500000 + angle * (2000000/180);
    }
};

#endif