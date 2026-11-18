// Source exposure: binary-analysis; no external implementation reused.
// LeafForward834650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x834650 LeafForward834650::Forward
#include "LeafForward834650.h"
extern "C" void* leaf_target(void*);
void* LeafForward834650::Forward() { return leaf_target(this); }
