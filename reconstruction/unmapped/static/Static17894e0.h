// Source exposure: binary-analysis; no external implementation source reused.
// Static17894e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17894e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17894e0*);
    virtual void release(Static17894e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17894e0*);
struct Static17894e0 {
    void* value;
    Static17894e0();
    ~Static17894e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
