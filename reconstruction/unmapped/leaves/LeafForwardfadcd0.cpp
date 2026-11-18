// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfadcd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfadcd0 LeafForwardfadcd0::Forward
#include "LeafForwardfadcd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfadcd0::Forward() { return leaf_target(this); }
