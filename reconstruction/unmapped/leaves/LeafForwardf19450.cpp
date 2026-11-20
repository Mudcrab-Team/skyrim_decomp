// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf19450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf19450 LeafForwardf19450::Forward
#include "LeafForwardf19450.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf19450::Forward() { return leaf_target(this); }
