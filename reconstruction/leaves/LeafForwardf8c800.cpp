// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8c800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8c800 LeafForwardf8c800::Forward
#include "LeafForwardf8c800.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8c800::Forward() { return leaf_target(this); }
