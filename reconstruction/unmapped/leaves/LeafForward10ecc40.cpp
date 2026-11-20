// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10ecc40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10ecc40 LeafForward10ecc40::Forward
#include "LeafForward10ecc40.h"
extern "C" void* leaf_target(void*);
void* LeafForward10ecc40::Forward() { return leaf_target(this); }
