// Source exposure: binary-analysis; no external implementation reused.
// LeafForward840630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x840630 LeafForward840630::Forward
#include "LeafForward840630.h"
extern "C" void* leaf_target(void*);
void* LeafForward840630::Forward() { return leaf_target(this); }
