// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1233260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1233260 LeafForward1233260::Forward
#include "LeafForward1233260.h"
extern "C" void* leaf_target(void*);
void* LeafForward1233260::Forward() { return leaf_target(this); }
