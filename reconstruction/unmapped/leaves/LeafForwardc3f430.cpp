// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc3f430, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc3f430 LeafForwardc3f430::Forward
#include "LeafForwardc3f430.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc3f430::Forward() { return leaf_target(this); }
