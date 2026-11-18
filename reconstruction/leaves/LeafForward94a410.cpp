// Source exposure: binary-analysis; no external implementation reused.
// LeafForward94a410, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x94a410 LeafForward94a410::Forward
#include "LeafForward94a410.h"
extern "C" void* leaf_target(void*);
void* LeafForward94a410::Forward() { return leaf_target(this); }
