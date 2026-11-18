// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8bcd70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8bcd70 LeafForward8bcd70::Forward
#include "LeafForward8bcd70.h"
extern "C" void* leaf_target(void*);
void* LeafForward8bcd70::Forward() { return leaf_target(this); }
