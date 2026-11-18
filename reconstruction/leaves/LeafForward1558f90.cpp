// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1558f90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1558f90 LeafForward1558f90::Forward
#include "LeafForward1558f90.h"
extern "C" void* leaf_target(void*);
void* LeafForward1558f90::Forward() { return leaf_target(this); }
