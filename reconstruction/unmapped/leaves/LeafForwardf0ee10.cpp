// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0ee10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0ee10 LeafForwardf0ee10::Forward
#include "LeafForwardf0ee10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0ee10::Forward() { return leaf_target(this); }
