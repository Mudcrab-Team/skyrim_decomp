// Source exposure: binary-analysis; no external implementation source reused.
// Static173fac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fac0*);
    virtual void release(Static173fac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fac0*);
struct Static173fac0 {
    void* value;
    Static173fac0();
    ~Static173fac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
