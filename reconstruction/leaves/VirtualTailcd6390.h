// Source exposure: binary-analysis; no external implementation reused.
// VirtualTailcd6390, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTailcd6390 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTailcd6390* object);
};
