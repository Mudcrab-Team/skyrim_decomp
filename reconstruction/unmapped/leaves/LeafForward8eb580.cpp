// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8eb580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8eb580 LeafForward8eb580::Forward
#include "LeafForward8eb580.h"
extern "C" void* leaf_target(void*);
void* LeafForward8eb580::Forward() { return leaf_target(this); }
