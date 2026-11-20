// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5c4610, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5c4610 LeafForward5c4610::Forward
#include "LeafForward5c4610.h"
extern "C" void* leaf_target(void*);
void* LeafForward5c4610::Forward() { return leaf_target(this); }
