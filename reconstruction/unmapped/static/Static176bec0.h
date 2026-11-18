// Source exposure: binary-analysis; no external implementation source reused.
// Static176bec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bec0*);
    virtual void release(Static176bec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bec0*);
struct Static176bec0 {
    void* value;
    Static176bec0();
    ~Static176bec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
