// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfce410, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfce410 LeafForwardfce410::Forward
#include "LeafForwardfce410.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfce410::Forward() { return leaf_target(this); }
