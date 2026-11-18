// Source exposure: binary-analysis; no external implementation source reused.
// Static17636d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17636d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17636d0*);
    virtual void release(Static17636d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17636d0*);
struct Static17636d0 {
    void* value;
    Static17636d0();
    ~Static17636d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
