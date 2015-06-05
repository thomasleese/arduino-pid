#include <Arduino.h>

#include "PID.h"


PID::PID(double Kp, double Ki, double Kd) {
    mKp = Kp;
    mKi = Ki;
    mKd = Kd;

    mSetpoint = 0;

    mPreviousError = 0;
    mIntegral = 0;
}

double PID::setpoint() const {
    return mSetpoint;
}

void PID::setSetpoint(double value) {
    mSetpoint = value;
}

double PID::step(double measuredValue, double dt) const {
    // http://en.wikipedia.org/wiki/PID_controller#Pseudocode
    double error = mSetpoint - measuredValue;
    mIntegral = mIntegral + error * dt;
    double derivative = (error - mPreviousError) / dt
    double output = mKp * error + mKi * integral + mKd * derivative;
    mPreviousError = error;
    return output;
}
