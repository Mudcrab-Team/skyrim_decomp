// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6e0600, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6e0600 LeafForward6e0600::Forward
#include "LeafForward6e0600.h"
extern "C" void* leaf_target(void*);
void* LeafForward6e0600::Forward() { return leaf_target(this); }
