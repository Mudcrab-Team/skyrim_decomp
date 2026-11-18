// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128b430, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128b430 LeafForward128b430::Forward
#include "LeafForward128b430.h"
extern "C" void* leaf_target(void*);
void* LeafForward128b430::Forward() { return leaf_target(this); }
