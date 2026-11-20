// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfadd00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfadd00 LeafForwardfadd00::Forward
#include "LeafForwardfadd00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfadd00::Forward() { return leaf_target(this); }
