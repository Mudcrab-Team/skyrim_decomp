// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11e6540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11e6540 LeafForward11e6540::Forward
#include "LeafForward11e6540.h"
extern "C" void* leaf_target(void*);
void* LeafForward11e6540::Forward() { return leaf_target(this); }
