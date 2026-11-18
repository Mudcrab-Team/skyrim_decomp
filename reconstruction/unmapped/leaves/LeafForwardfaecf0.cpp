// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaecf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaecf0 LeafForwardfaecf0::Forward
#include "LeafForwardfaecf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaecf0::Forward() { return leaf_target(this); }
