// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeaffa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeaffa0 LeafForwardeaffa0::Forward
#include "LeafForwardeaffa0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeaffa0::Forward() { return leaf_target(this); }
