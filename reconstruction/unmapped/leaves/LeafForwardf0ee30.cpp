// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0ee30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0ee30 LeafForwardf0ee30::Forward
#include "LeafForwardf0ee30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0ee30::Forward() { return leaf_target(this); }
