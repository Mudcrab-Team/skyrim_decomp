// Source exposure: binary-analysis; no external implementation source reused.
// Static176d0e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d0e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d0e0*);
    virtual void release(Static176d0e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d0e0*);
struct Static176d0e0 {
    void* value;
    Static176d0e0();
    ~Static176d0e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
