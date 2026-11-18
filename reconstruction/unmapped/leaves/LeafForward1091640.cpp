// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1091640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1091640 LeafForward1091640::Forward
#include "LeafForward1091640.h"
extern "C" void* leaf_target(void*);
void* LeafForward1091640::Forward() { return leaf_target(this); }
