// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122af30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122af30 LeafForward122af30::Forward
#include "LeafForward122af30.h"
extern "C" void* leaf_target(void*);
void* LeafForward122af30::Forward() { return leaf_target(this); }
