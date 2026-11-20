// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1f6160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1f6160 LeafForward1f6160::Forward
#include "LeafForward1f6160.h"
extern "C" void* leaf_target(void*);
void* LeafForward1f6160::Forward() { return leaf_target(this); }
