// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf19480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf19480 LeafForwardf19480::Forward
#include "LeafForwardf19480.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf19480::Forward() { return leaf_target(this); }
