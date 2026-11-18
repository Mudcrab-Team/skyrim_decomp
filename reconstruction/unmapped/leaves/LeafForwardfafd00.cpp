// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfafd00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfafd00 LeafForwardfafd00::Forward
#include "LeafForwardfafd00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfafd00::Forward() { return leaf_target(this); }
