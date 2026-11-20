// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83fc80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83fc80 LeafForward83fc80::Forward
#include "LeafForward83fc80.h"
extern "C" void* leaf_target(void*);
void* LeafForward83fc80::Forward() { return leaf_target(this); }
