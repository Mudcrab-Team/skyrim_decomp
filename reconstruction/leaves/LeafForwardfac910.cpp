// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfac910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfac910 LeafForwardfac910::Forward
#include "LeafForwardfac910.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfac910::Forward() { return leaf_target(this); }
