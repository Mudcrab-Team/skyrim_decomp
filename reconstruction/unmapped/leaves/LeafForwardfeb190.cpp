// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfeb190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfeb190 LeafForwardfeb190::Forward
#include "LeafForwardfeb190.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfeb190::Forward() { return leaf_target(this); }
