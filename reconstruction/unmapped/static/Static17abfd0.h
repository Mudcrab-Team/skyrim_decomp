// Source exposure: binary-analysis; no external implementation source reused.
// Static17abfd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abfd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abfd0*);
    virtual void release(Static17abfd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abfd0*);
struct Static17abfd0 {
    void* value;
    Static17abfd0();
    ~Static17abfd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
