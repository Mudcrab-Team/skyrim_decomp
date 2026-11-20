// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8cc580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8cc580 LeafForward8cc580::Forward
#include "LeafForward8cc580.h"
extern "C" void* leaf_target(void*);
void* LeafForward8cc580::Forward() { return leaf_target(this); }
