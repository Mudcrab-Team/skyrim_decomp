// Source exposure: binary-analysis; no external implementation source reused.
// Static17666a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17666a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17666a0*);
    virtual void release(Static17666a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17666a0*);
struct Static17666a0 {
    void* value;
    Static17666a0();
    ~Static17666a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
