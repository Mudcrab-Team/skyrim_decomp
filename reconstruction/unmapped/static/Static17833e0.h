// Source exposure: binary-analysis; no external implementation source reused.
// Static17833e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17833e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17833e0*);
    virtual void release(Static17833e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17833e0*);
struct Static17833e0 {
    void* value;
    Static17833e0();
    ~Static17833e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
