// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf171c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf171c0 LeafForwardf171c0::Forward
#include "LeafForwardf171c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf171c0::Forward() { return leaf_target(this); }
