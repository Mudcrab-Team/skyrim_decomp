// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b160 LeafForward153b160::Forward
#include "LeafForward153b160.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b160::Forward() { return leaf_target(this); }
