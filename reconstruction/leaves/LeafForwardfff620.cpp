// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfff620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfff620 LeafForwardfff620::Forward
#include "LeafForwardfff620.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfff620::Forward() { return leaf_target(this); }
