// Source exposure: binary-analysis; no external implementation source reused.
// Static17771d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17771d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17771d0*);
    virtual void release(Static17771d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17771d0*);
struct Static17771d0 {
    void* value;
    Static17771d0();
    ~Static17771d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
