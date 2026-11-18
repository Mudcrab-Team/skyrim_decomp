// Source exposure: binary-analysis; no external implementation source reused.
// Static17518e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17518e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17518e0*);
    virtual void release(Static17518e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17518e0*);
struct Static17518e0 {
    void* value;
    Static17518e0();
    ~Static17518e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
