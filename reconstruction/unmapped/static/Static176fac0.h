// Source exposure: binary-analysis; no external implementation source reused.
// Static176fac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fac0*);
    virtual void release(Static176fac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fac0*);
struct Static176fac0 {
    void* value;
    Static176fac0();
    ~Static176fac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
