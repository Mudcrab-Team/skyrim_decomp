// Source exposure: binary-analysis; no external implementation reused.
// VirtualTail1223550, Dispatch, Invoke, object: GUESS(low) STANDIN
// Origin: nullable-virtual-tail v1
#pragma once
class VirtualTail1223550 {
public:
    virtual void Invoke(unsigned int);
    void Dispatch(VirtualTail1223550* object);
};
