// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7c8090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7c8090 LeafForward7c8090::Forward
#include "LeafForward7c8090.h"
extern "C" void* leaf_target(void*);
void* LeafForward7c8090::Forward() { return leaf_target(this); }
