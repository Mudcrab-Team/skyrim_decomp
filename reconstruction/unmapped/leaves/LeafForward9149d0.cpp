// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9149d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9149d0 LeafForward9149d0::Forward
#include "LeafForward9149d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9149d0::Forward() { return leaf_target(this); }
