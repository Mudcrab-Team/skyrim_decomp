// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb09ab0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb09ab0 LeafForwardb09ab0::Forward
#include "LeafForwardb09ab0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb09ab0::Forward() { return leaf_target(this); }
