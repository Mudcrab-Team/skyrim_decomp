// Source exposure: binary-analysis; no external implementation reused.
// LeafForward61e880, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x61e880 LeafForward61e880::Forward
#include "LeafForward61e880.h"
extern "C" void* leaf_target(void*);
void* LeafForward61e880::Forward() { return leaf_target(this); }
