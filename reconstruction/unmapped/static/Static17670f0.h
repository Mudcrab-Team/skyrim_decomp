// Source exposure: binary-analysis; no external implementation source reused.
// Static17670f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17670f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17670f0*);
    virtual void release(Static17670f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17670f0*);
struct Static17670f0 {
    void* value;
    Static17670f0();
    ~Static17670f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
