// Source exposure: binary-analysis; no external implementation reused.
// LeafForward31aa40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x31aa40 LeafForward31aa40::Forward
#include "LeafForward31aa40.h"
extern "C" void* leaf_target(void*);
void* LeafForward31aa40::Forward() { return leaf_target(this); }
