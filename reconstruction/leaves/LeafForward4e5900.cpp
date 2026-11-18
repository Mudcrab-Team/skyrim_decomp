// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4e5900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4e5900 LeafForward4e5900::Forward
#include "LeafForward4e5900.h"
extern "C" void* leaf_target(void*);
void* LeafForward4e5900::Forward() { return leaf_target(this); }
