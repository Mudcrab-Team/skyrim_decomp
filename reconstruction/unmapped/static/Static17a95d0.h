// Source exposure: binary-analysis; no external implementation source reused.
// Static17a95d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a95d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a95d0*);
    virtual void release(Static17a95d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a95d0*);
struct Static17a95d0 {
    void* value;
    Static17a95d0();
    ~Static17a95d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
