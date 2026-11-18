// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14a1510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14a1510 LeafForward14a1510::Forward
#include "LeafForward14a1510.h"
extern "C" void* leaf_target(void*);
void* LeafForward14a1510::Forward() { return leaf_target(this); }
