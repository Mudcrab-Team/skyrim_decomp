// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail80ff00, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail80ff00 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail80ff00* object);
};
