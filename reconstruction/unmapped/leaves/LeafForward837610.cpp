// Source exposure: binary-analysis; no external implementation reused.
// LeafForward837610, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x837610 LeafForward837610::Forward
#include "LeafForward837610.h"
extern "C" void* leaf_target(void*);
void* LeafForward837610::Forward() { return leaf_target(this); }
