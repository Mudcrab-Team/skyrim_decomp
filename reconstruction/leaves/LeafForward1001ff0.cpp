// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1001ff0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1001ff0 LeafForward1001ff0::Forward
#include "LeafForward1001ff0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1001ff0::Forward() { return leaf_target(this); }
