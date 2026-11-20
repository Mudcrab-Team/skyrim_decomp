// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardabe950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xabe950 LeafForwardabe950::Forward
#include "LeafForwardabe950.h"
extern "C" void* leaf_target(void*);
void* LeafForwardabe950::Forward() { return leaf_target(this); }
