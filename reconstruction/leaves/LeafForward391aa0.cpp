// Source exposure: binary-analysis; no external implementation reused.
// LeafForward391aa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x391aa0 LeafForward391aa0::Forward
#include "LeafForward391aa0.h"
extern "C" void* leaf_target(void*);
void* LeafForward391aa0::Forward() { return leaf_target(this); }
