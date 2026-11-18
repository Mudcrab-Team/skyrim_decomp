// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6bf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6bf0 LeafForwardff6bf0::Forward
#include "LeafForwardff6bf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6bf0::Forward() { return leaf_target(this); }
