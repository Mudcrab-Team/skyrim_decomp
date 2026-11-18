// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11e9330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11e9330 LeafForward11e9330::Forward
#include "LeafForward11e9330.h"
extern "C" void* leaf_target(void*);
void* LeafForward11e9330::Forward() { return leaf_target(this); }
