// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1d00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1d00 LeafForwardfb1d00::Forward
#include "LeafForwardfb1d00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1d00::Forward() { return leaf_target(this); }
