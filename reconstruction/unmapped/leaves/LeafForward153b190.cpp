// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b190 LeafForward153b190::Forward
#include "LeafForward153b190.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b190::Forward() { return leaf_target(this); }
