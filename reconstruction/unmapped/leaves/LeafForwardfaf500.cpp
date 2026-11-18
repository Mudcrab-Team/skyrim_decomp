// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf500 LeafForwardfaf500::Forward
#include "LeafForwardfaf500.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf500::Forward() { return leaf_target(this); }
