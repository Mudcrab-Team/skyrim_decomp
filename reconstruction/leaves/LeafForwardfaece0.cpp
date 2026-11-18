// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaece0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaece0 LeafForwardfaece0::Forward
#include "LeafForwardfaece0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaece0::Forward() { return leaf_target(this); }
