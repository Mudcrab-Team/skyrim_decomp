// Source exposure: binary-analysis; no external implementation source reused.
// Static17712d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17712d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17712d0*);
    virtual void release(Static17712d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17712d0*);
struct Static17712d0 {
    void* value;
    Static17712d0();
    ~Static17712d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
