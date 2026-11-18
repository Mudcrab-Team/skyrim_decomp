// Source exposure: binary-analysis; no external implementation reused.
// LeafForward871200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x871200 LeafForward871200::Forward
#include "LeafForward871200.h"
extern "C" void* leaf_target(void*);
void* LeafForward871200::Forward() { return leaf_target(this); }
