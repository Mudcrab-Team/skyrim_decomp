// Source exposure: binary-analysis; no external implementation reused.
// LeafForward13f2320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x13f2320 LeafForward13f2320::Forward
#include "LeafForward13f2320.h"
extern "C" void* leaf_target(void*);
void* LeafForward13f2320::Forward() { return leaf_target(this); }
