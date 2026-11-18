// Source exposure: binary-analysis; no external implementation source reused.
// Static17681d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17681d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17681d0*);
    virtual void release(Static17681d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17681d0*);
struct Static17681d0 {
    void* value;
    Static17681d0();
    ~Static17681d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
