// Source exposure: binary-analysis; no external implementation reused.
// LeafForward388870, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x388870 LeafForward388870::Forward
#include "LeafForward388870.h"
extern "C" void* leaf_target(void*);
void* LeafForward388870::Forward() { return leaf_target(this); }
