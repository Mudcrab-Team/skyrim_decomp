// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ee620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ee620 LeafForward8ee620::Forward
#include "LeafForward8ee620.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ee620::Forward() { return leaf_target(this); }
