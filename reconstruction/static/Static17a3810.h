// Source exposure: binary-analysis; no external implementation source reused.
// Static17a3810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a3810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a3810*);
    virtual void release(Static17a3810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a3810*);
struct Static17a3810 {
    void* value;
    Static17a3810();
    ~Static17a3810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
