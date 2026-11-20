// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfadcc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfadcc0 LeafForwardfadcc0::Forward
#include "LeafForwardfadcc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfadcc0::Forward() { return leaf_target(this); }
