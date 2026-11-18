// Source exposure: binary-analysis; no external implementation reused.
// LeafForward610430, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x610430 LeafForward610430::Forward
#include "LeafForward610430.h"
extern "C" void* leaf_target(void*);
void* LeafForward610430::Forward() { return leaf_target(this); }
