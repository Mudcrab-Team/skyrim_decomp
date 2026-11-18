// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6bafb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6bafb0 LeafForward6bafb0::Forward
#include "LeafForward6bafb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward6bafb0::Forward() { return leaf_target(this); }
