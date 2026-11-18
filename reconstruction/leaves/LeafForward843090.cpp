// Source exposure: binary-analysis; no external implementation reused.
// LeafForward843090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x843090 LeafForward843090::Forward
#include "LeafForward843090.h"
extern "C" void* leaf_target(void*);
void* LeafForward843090::Forward() { return leaf_target(this); }
