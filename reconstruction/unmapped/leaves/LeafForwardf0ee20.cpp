// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0ee20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0ee20 LeafForwardf0ee20::Forward
#include "LeafForwardf0ee20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0ee20::Forward() { return leaf_target(this); }
