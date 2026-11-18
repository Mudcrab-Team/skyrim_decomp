// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ed8f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ed8f0 LeafForward9ed8f0::Forward
#include "LeafForward9ed8f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ed8f0::Forward() { return leaf_target(this); }
