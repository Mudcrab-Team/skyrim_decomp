// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1b3050, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1b3050 LeafForward1b3050::Forward
#include "LeafForward1b3050.h"
extern "C" void* leaf_target(void*);
void* LeafForward1b3050::Forward() { return leaf_target(this); }
