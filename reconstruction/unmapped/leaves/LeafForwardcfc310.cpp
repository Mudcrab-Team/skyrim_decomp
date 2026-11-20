// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcfc310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcfc310 LeafForwardcfc310::Forward
#include "LeafForwardcfc310.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcfc310::Forward() { return leaf_target(this); }
