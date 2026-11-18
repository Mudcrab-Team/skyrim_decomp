// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf62dc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf62dc0 LeafForwardf62dc0::Forward
#include "LeafForwardf62dc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf62dc0::Forward() { return leaf_target(this); }
