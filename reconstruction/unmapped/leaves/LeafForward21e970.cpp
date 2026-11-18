// Source exposure: binary-analysis; no external implementation reused.
// LeafForward21e970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x21e970 LeafForward21e970::Forward
#include "LeafForward21e970.h"
extern "C" void* leaf_target(void*);
void* LeafForward21e970::Forward() { return leaf_target(this); }
