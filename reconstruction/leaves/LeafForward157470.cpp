// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157470 LeafForward157470::Forward
#include "LeafForward157470.h"
extern "C" void* leaf_target(void*);
void* LeafForward157470::Forward() { return leaf_target(this); }
