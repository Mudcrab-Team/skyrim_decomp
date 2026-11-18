// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5c9090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5c9090 LeafForward5c9090::Forward
#include "LeafForward5c9090.h"
extern "C" void* leaf_target(void*);
void* LeafForward5c9090::Forward() { return leaf_target(this); }
