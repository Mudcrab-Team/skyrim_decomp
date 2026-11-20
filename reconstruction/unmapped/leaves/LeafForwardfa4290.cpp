// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4290 LeafForwardfa4290::Forward
#include "LeafForwardfa4290.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4290::Forward() { return leaf_target(this); }
