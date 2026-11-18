// Source exposure: binary-analysis; no external implementation reused.
// LeafForward61b190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x61b190 LeafForward61b190::Forward
#include "LeafForward61b190.h"
extern "C" void* leaf_target(void*);
void* LeafForward61b190::Forward() { return leaf_target(this); }
