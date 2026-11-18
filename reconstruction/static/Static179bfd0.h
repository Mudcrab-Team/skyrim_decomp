// Source exposure: binary-analysis; no external implementation source reused.
// Static179bfd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bfd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bfd0*);
    virtual void release(Static179bfd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bfd0*);
struct Static179bfd0 {
    void* value;
    Static179bfd0();
    ~Static179bfd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
