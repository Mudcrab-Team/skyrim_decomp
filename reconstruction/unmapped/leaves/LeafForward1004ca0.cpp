// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1004ca0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1004ca0 LeafForward1004ca0::Forward
#include "LeafForward1004ca0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1004ca0::Forward() { return leaf_target(this); }
