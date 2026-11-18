// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf67bf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf67bf0 LeafForwardf67bf0::Forward
#include "LeafForwardf67bf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf67bf0::Forward() { return leaf_target(this); }
