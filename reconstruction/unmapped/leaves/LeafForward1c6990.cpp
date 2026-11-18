// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1c6990, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1c6990 LeafForward1c6990::Forward
#include "LeafForward1c6990.h"
extern "C" void* leaf_target(void*);
void* LeafForward1c6990::Forward() { return leaf_target(this); }
