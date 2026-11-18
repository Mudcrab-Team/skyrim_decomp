// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfadce0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfadce0 LeafForwardfadce0::Forward
#include "LeafForwardfadce0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfadce0::Forward() { return leaf_target(this); }
