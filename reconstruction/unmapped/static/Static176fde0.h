// Source exposure: binary-analysis; no external implementation source reused.
// Static176fde0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fde0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fde0*);
    virtual void release(Static176fde0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fde0*);
struct Static176fde0 {
    void* value;
    Static176fde0();
    ~Static176fde0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
