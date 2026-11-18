// Source exposure: binary-analysis; no external implementation source reused.
// Static176bce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bce0*);
    virtual void release(Static176bce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bce0*);
struct Static176bce0 {
    void* value;
    Static176bce0();
    ~Static176bce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
