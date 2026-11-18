// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef26a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef26a0 LeafForwardef26a0::Forward
#include "LeafForwardef26a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef26a0::Forward() { return leaf_target(this); }
