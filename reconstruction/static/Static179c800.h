// Source exposure: binary-analysis; no external implementation source reused.
// Static179c800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c800*);
    virtual void release(Static179c800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c800*);
struct Static179c800 {
    void* value;
    Static179c800();
    ~Static179c800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
