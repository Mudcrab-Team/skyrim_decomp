// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76090 LeafForwardf76090::Forward
#include "LeafForwardf76090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76090::Forward() { return leaf_target(this); }
