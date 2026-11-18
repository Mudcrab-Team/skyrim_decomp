// Source exposure: binary-analysis; no external implementation reused.
// LeafForward106b100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x106b100 LeafForward106b100::Forward
#include "LeafForward106b100.h"
extern "C" void* leaf_target(void*);
void* LeafForward106b100::Forward() { return leaf_target(this); }
