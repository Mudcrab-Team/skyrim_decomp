// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf86090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf86090 LeafForwardf86090::Forward
#include "LeafForwardf86090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf86090::Forward() { return leaf_target(this); }
