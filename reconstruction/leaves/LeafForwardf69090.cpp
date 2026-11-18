// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69090 LeafForwardf69090::Forward
#include "LeafForwardf69090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69090::Forward() { return leaf_target(this); }
