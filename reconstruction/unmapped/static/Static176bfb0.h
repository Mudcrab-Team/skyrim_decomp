// Source exposure: binary-analysis; no external implementation source reused.
// Static176bfb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bfb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bfb0*);
    virtual void release(Static176bfb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bfb0*);
struct Static176bfb0 {
    void* value;
    Static176bfb0();
    ~Static176bfb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
