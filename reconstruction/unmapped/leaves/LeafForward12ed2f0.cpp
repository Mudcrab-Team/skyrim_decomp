// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12ed2f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12ed2f0 LeafForward12ed2f0::Forward
#include "LeafForward12ed2f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward12ed2f0::Forward() { return leaf_target(this); }
