// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf0c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf0c0 LeafForwardfaf0c0::Forward
#include "LeafForwardfaf0c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf0c0::Forward() { return leaf_target(this); }
