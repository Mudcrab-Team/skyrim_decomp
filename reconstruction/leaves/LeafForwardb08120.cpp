// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb08120, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb08120 LeafForwardb08120::Forward
#include "LeafForwardb08120.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb08120::Forward() { return leaf_target(this); }
