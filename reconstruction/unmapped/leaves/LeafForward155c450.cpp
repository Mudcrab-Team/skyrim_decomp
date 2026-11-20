// Source exposure: binary-analysis; no external implementation reused.
// LeafForward155c450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x155c450 LeafForward155c450::Forward
#include "LeafForward155c450.h"
extern "C" void* leaf_target(void*);
void* LeafForward155c450::Forward() { return leaf_target(this); }
