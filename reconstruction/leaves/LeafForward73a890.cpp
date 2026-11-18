// Source exposure: binary-analysis; no external implementation reused.
// LeafForward73a890, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x73a890 LeafForward73a890::Forward
#include "LeafForward73a890.h"
extern "C" void* leaf_target(void*);
void* LeafForward73a890::Forward() { return leaf_target(this); }
