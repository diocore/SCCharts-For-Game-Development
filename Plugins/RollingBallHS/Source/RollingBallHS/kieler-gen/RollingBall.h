#ifndef ROLLINGBALL_H
#define ROLLINGBALL_H
/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

typedef struct {
  double accel;
  double targetV;
  double currentV;
  double Kp;
  double Ki;
  double Kd;
  double dT;
  double prevError;
  double error;
  double P;
  double I;
  double D;
  double t;
  double deltaT;
  double sleepT;
  char _GO;
  char _TERM;
} TickData;

void reset(TickData* d);
void logic(TickData* d);
void tick(TickData* d);

#endif /* !ROLLINGBALL_H */
