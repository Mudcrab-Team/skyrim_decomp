// Source exposure: binary-analysis; no external implementation source reused.
// Static17644e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17644e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17644e0*);
    virtual void release(Static17644e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17644e0*);
struct Static17644e0 {
    void* value;
    Static17644e0();
    ~Static17644e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
