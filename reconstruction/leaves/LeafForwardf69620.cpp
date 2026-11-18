// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69620 LeafForwardf69620::Forward
#include "LeafForwardf69620.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69620::Forward() { return leaf_target(this); }
