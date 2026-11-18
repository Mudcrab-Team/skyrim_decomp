// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157bde0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157bde0 LeafForward157bde0::Forward
#include "LeafForward157bde0.h"
extern "C" void* leaf_target(void*);
void* LeafForward157bde0::Forward() { return leaf_target(this); }
