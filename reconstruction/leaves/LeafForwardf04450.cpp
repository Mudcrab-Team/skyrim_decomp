// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf04450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf04450 LeafForwardf04450::Forward
#include "LeafForwardf04450.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf04450::Forward() { return leaf_target(this); }
