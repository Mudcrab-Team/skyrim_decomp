// Source exposure: binary-analysis; no external implementation source reused.
// Static176bba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bba0*);
    virtual void release(Static176bba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bba0*);
struct Static176bba0 {
    void* value;
    Static176bba0();
    ~Static176bba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
