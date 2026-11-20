// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a56e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a56e0 LeafForward7a56e0::Forward
#include "LeafForward7a56e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a56e0::Forward() { return leaf_target(this); }
