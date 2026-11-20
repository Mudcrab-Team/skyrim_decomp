// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbbc0a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbbc0a0 LeafForwardbbc0a0::Forward
#include "LeafForwardbbc0a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbbc0a0::Forward() { return leaf_target(this); }
