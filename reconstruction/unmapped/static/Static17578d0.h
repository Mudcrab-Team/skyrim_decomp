// Source exposure: binary-analysis; no external implementation source reused.
// Static17578d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17578d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17578d0*);
    virtual void release(Static17578d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17578d0*);
struct Static17578d0 {
    void* value;
    Static17578d0();
    ~Static17578d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
