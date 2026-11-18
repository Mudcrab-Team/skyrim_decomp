// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail831980, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail831980 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail831980* object);
};
