// Source exposure: binary-analysis; no external implementation reused.
// LeafForward18eb60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x18eb60 LeafForward18eb60::Forward
#include "LeafForward18eb60.h"
extern "C" void* leaf_target(void*);
void* LeafForward18eb60::Forward() { return leaf_target(this); }
