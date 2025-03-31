// pwm.h
#ifndef PWN_H
#define PWN_H

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
// Reference: https://github.com/berndporr/rpi_pwm

/**
 * @brief PWM control class, based on the sysfs interface to control the PWM output on the Raspberry Pi.
 * @brief This class encapsulates operations on the period, duty_cycle, enable files under /sys/class/pwm/pwmchipX/pwmY.
 */
class PWM
{
public:
    int start_pwm(int channel, int frequency, float duty_cycle, int chip = 2);
    inline int setDutyCycle(float v) const;

    ~PWM()
    {
        disable();
    }

private:
    string chippath;
    string pwmpath;
    int per = 0;

    inline int writeSYS(std::string filename, int value) const
    {
        FILE *const fp = fopen(filename.c_str(), "w");
        if (NULL == fp)
        {
            return -1;
        }
        const int r = fprintf(fp, "%d", value);
        fclose(fp);
        return r;
    }

    void setPeriod(int ns) const
    {
        writeSYS(pwmpath + "/" + "period", ns);
    }

    inline int setDutyCycleNS(int ns) const
    {
        const int r = writeSYS(pwmpath + "/" + "duty_cycle", ns);
        return r;
    }

    void enable() const
    {
        writeSYS(pwmpath + "/" + "enable", 1);
    }

    void disable() const
    {
        writeSYS(pwmpath + "/" + "enable", 0);
    }
};

#endif