/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "Elevator.h"

void logic(TickData* d) {
  d->_g27 = d->_pg19;
  d->_cg27 = d->targetFloor == d->currentFloor;
  d->_g30 = d->_pg8_e1;
  d->_cg30 = d->targetFloor == d->currentFloor;
  d->_g2 = d->_GO || d->_g27 && d->_cg27 || d->_g30 && d->_cg30;
  if (d->_g2) {
    d->_Tterm = 0;
    d->_Atrig = 0;
    d->_Atrig1 = 0;
    d->stateID = 1;
  }
  d->_g14 = d->_pg7;
  d->_cg14 = !d->doorOpen;
  d->_g15 = d->_g14 && d->_cg14;
  if (d->_g15) {
    d->_Tterm = 1;
  }
  d->_g19 = d->_pg12;
  d->_cg19 = d->targetFloor > d->currentFloor && d->_Tterm;
  d->_g20 = d->_g19 && d->_cg19;
  if (d->_g20) {
    d->_Atrig = 1;
  }
  d->_g22 = d->_g19 && !d->_cg19;
  d->_cg22 = d->targetFloor < d->currentFloor && d->_Tterm;
  d->_g23 = d->_g22 && d->_cg22;
  if (d->_g23) {
    d->_Atrig1 = 1;
  }
  d->_g5 = d->_pg4;
  d->_g16 = d->_g5 && !d->doorOpen;
  d->_cg16 = d->_Atrig || d->_Atrig1;
  d->_g4 = d->_g2 || d->_g16 && !d->_cg16;
  d->_g6 = d->_g5 && d->doorOpen;
  if (d->_g6) {
    d->stateID = 2;
  }
  d->_g10 = d->_pg16;
  d->_cg10 = d->targetFloor != d->currentFloor;
  d->_g6 = d->_g6 || d->_g10 && !d->_cg10;
  d->_cg7 = d->_Atrig || d->_Atrig1;
  d->_g11 = d->_g10 && d->_cg10;
  if (d->_g11) {
    d->stateID = 3;
  }
  d->_g11 = d->_g11 || d->_g14 && !d->_cg14;
  d->_cg12 = d->_Atrig || d->_Atrig1;
  d->_g15 = d->_g6 && d->_cg7 || d->_g11 && d->_cg12 || d->_g15 || d->_g16 && d->_cg16;
  d->_g16 = d->_g6 && !d->_cg7;
  d->_g7 = d->_g11 && !d->_cg12;
  d->_g12 = d->_g2 || d->_g22 && !d->_cg22;
  d->_g22 = d->_g20 || d->_g23;
  d->_g2 = !(d->_g5 || d->_g10 || d->_g14);
  d->_g23 = !d->_g19;
  d->_g20 = (d->_g2 || d->_g15) && (d->_g23 || d->_g22) && (d->_g15 || d->_g22);
  d->_cg24 = d->_Atrig;
  d->_g5 = d->_g20 && d->_cg24;
  if (d->_g5) {
    d->numFloorsToMove = d->targetFloor - d->currentFloor;
    d->stateID = 4;
  }
  d->_g14 = d->_pg10;
  d->_g10 = d->_GO || d->_g14;
  if (d->_g10) {
    d->moveUp = 0;
    d->moveDown = 0;
  }
  if (d->_g5) {
    d->moveUp |= 1;
  }
  d->_g19 = d->_g5 || d->_g27 && !d->_cg27;
  d->_g8 = d->_g20 && !d->_cg24;
  if (d->_g8) {
    d->numFloorsToMove = d->currentFloor - d->targetFloor;
    d->stateID = 5;
    d->moveDown |= 1;
  }
  d->_g8_e1 = d->_g8 || d->_g30 && !d->_cg30;
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->_pg19 = 0;
  d->_pg8_e1 = 0;
  d->_pg7 = 0;
  d->_pg12 = 0;
  d->_pg4 = 0;
  d->_pg16 = 0;
  d->_pg10 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg19 = d->_g19;
  d->_pg8_e1 = d->_g8_e1;
  d->_pg7 = d->_g7;
  d->_pg12 = d->_g12;
  d->_pg4 = d->_g4;
  d->_pg16 = d->_g16;
  d->_pg10 = d->_g10;
  d->_GO = 0;
}
