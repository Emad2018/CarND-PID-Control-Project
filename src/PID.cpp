#include <vector>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte)
{
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = Kp * cte;

  errors += cte;
  i_error = Ki * errors;

  d_error = Kd * (cte - prev_cte);
  prev_cte = cte;
}

double PID::TotalError()
{
  /**
   * TODO: Calculate and return the total error
   */
  double steer = -p_error - d_error - i_error;
  if (steer > 1)
  {
    steer = 1;
  }
  else if (steer < -1)
  {
    steer = -1;
  }

  return steer; // TODO: Add your total error calc here!
}