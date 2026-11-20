// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83e380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83e380 LeafForward83e380::Forward
#include "LeafForward83e380.h"
extern "C" void* leaf_target(void*);
void* LeafForward83e380::Forward() { return leaf_target(this); }
