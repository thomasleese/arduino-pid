/*
  PID.h - Library implementing a PID controller.
  Created by Tom Leese, June 5, 2015.
  Released under the MIT License.
*/

#ifndef PID_H
#define PID_H

class PID {

public:
    PID(double Kp, double Ki, double Kd);

    double setpoint() const;
    void setSetpoint(double value);

    double step(double measuredValue, double dt) const;

private:
    double mKp;
    double mKi;
    double mKd;

    double mSetpoint;

    double mPreviousError;
    double mIntegral;

};

#endif // PID_H
