// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157df90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157df90 LeafForward157df90::Forward
#include "LeafForward157df90.h"
extern "C" void* leaf_target(void*);
void* LeafForward157df90::Forward() { return leaf_target(this); }
