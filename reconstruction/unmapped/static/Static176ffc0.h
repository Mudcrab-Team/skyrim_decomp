// Source exposure: binary-analysis; no external implementation source reused.
// Static176ffc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ffc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ffc0*);
    virtual void release(Static176ffc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ffc0*);
struct Static176ffc0 {
    void* value;
    Static176ffc0();
    ~Static176ffc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
