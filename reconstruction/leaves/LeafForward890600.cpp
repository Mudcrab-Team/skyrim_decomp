// Source exposure: binary-analysis; no external implementation reused.
// LeafForward890600, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x890600 LeafForward890600::Forward
#include "LeafForward890600.h"
extern "C" void* leaf_target(void*);
void* LeafForward890600::Forward() { return leaf_target(this); }
