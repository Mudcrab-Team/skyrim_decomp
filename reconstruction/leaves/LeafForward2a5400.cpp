// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2a5400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2a5400 LeafForward2a5400::Forward
#include "LeafForward2a5400.h"
extern "C" void* leaf_target(void*);
void* LeafForward2a5400::Forward() { return leaf_target(this); }
