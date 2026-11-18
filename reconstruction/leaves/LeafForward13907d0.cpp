// Source exposure: binary-analysis; no external implementation reused.
// LeafForward13907d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x13907d0 LeafForward13907d0::Forward
#include "LeafForward13907d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward13907d0::Forward() { return leaf_target(this); }
