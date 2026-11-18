// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc44cd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc44cd0 LeafForwardc44cd0::Forward
#include "LeafForwardc44cd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc44cd0::Forward() { return leaf_target(this); }
