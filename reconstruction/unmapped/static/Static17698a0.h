// Source exposure: binary-analysis; no external implementation source reused.
// Static17698a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17698a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17698a0*);
    virtual void release(Static17698a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17698a0*);
struct Static17698a0 {
    void* value;
    Static17698a0();
    ~Static17698a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
