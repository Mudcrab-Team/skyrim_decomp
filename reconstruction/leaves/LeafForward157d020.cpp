// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157d020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157d020 LeafForward157d020::Forward
#include "LeafForward157d020.h"
extern "C" void* leaf_target(void*);
void* LeafForward157d020::Forward() { return leaf_target(this); }
