// Source exposure: binary-analysis; no external implementation reused.
// LeafForward82e290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x82e290 LeafForward82e290::Forward
#include "LeafForward82e290.h"
extern "C" void* leaf_target(void*);
void* LeafForward82e290::Forward() { return leaf_target(this); }
