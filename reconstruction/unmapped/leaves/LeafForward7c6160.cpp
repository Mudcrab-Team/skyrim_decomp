// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7c6160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7c6160 LeafForward7c6160::Forward
#include "LeafForward7c6160.h"
extern "C" void* leaf_target(void*);
void* LeafForward7c6160::Forward() { return leaf_target(this); }
