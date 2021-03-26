#ifndef ELEVATOR_H
#define ELEVATOR_H
/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

typedef struct {
  int stateID;
  int currentFloor;
  int targetFloor;
  int numFloorsToMove;
  char doorOpen;
  char moveUp;
  char moveDown;
  char _Tterm;
  char _Atrig;
  char _Atrig1;
  char _g2;
  char _g4;
  char _g5;
  char _g6;
  char _g7;
  char _g8;
  char _g10;
  char _g11;
  char _g12;
  char _g14;
  char _g15;
  char _g16;
  char _g19;
  char _g20;
  char _g22;
  char _g23;
  char _g27;
  char _g30;
  char _GO;
  char _cg27;
  char _cg30;
  char _cg16;
  char _cg5;
  char _cg10;
  char _cg7;
  char _cg12;
  char _cg14;
  char _cg22;
  char _cg19;
  char _cg24;
  char _g8_e1;
  char _TERM;
  char _pg19;
  char _pg8_e1;
  char _pg7;
  char _pg12;
  char _pg4;
  char _pg16;
  char _pg10;
} TickData;

void reset(TickData* d);
void logic(TickData* d);
void tick(TickData* d);

#endif /* !ELEVATOR_H */
