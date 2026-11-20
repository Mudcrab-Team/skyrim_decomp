// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfadcf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfadcf0 LeafForwardfadcf0::Forward
#include "LeafForwardfadcf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfadcf0::Forward() { return leaf_target(this); }
