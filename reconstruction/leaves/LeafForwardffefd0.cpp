// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardffefd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xffefd0 LeafForwardffefd0::Forward
#include "LeafForwardffefd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardffefd0::Forward() { return leaf_target(this); }
