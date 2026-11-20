// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14e7580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14e7580 LeafForward14e7580::Forward
#include "LeafForward14e7580.h"
extern "C" void* leaf_target(void*);
void* LeafForward14e7580::Forward() { return leaf_target(this); }
