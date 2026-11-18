// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7b9150, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7b9150 LeafForward7b9150::Forward
#include "LeafForward7b9150.h"
extern "C" void* leaf_target(void*);
void* LeafForward7b9150::Forward() { return leaf_target(this); }
