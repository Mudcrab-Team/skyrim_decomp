// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7ab630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7ab630 LeafForward7ab630::Forward
#include "LeafForward7ab630.h"
extern "C" void* leaf_target(void*);
void* LeafForward7ab630::Forward() { return leaf_target(this); }
