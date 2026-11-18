// Source exposure: binary-analysis; no external implementation reused.
// LeafForward848a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x848a60 LeafForward848a60::Forward
#include "LeafForward848a60.h"
extern "C" void* leaf_target(void*);
void* LeafForward848a60::Forward() { return leaf_target(this); }
