/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "RollingBall.h"

void logic(TickData* d) {
  d->error = d->targetV - d->currentV;
  d->prevError = d->error;
  d->P = d->Kp * d->error;
  if (!d->_GO) {
    d->t += d->deltaT;
  }
  d->I += d->error * d->t;
  d->D = (d->currentV - d->prevError) / d->t;
  d->accel = d->P + d->Ki * d->I + d->Kd * d->D;
  d->sleepT = 1000.0;
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->targetV = 10;
  d->currentV = 0;
  d->dT = 0;
  d->prevError = 0;
  d->error = 0;
  d->t = 0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
}

void tick(TickData* d) {
  logic(d);

  d->_GO = 0;
}
