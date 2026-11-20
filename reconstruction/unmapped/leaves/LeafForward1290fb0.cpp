// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1290fb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1290fb0 LeafForward1290fb0::Forward
#include "LeafForward1290fb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1290fb0::Forward() { return leaf_target(this); }
