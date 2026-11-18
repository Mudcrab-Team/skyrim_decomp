// Source exposure: binary-analysis; no external implementation source reused.
// Code origin: original reconstruction from binary analysis.
// Origin: storage-adapter-initializer v2
// 0x3f0a70 StorageInit3f0a70::initialize
#include "StorageInit3f0a70.h"
unsigned StorageInit3f0a70::initialize(void* object)
{
    Adapter adapter(object);
    unsigned& count = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 8);
    unsigned& storage = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 16);
    return storage_helper(&storage, &adapter, count, 8);
}
