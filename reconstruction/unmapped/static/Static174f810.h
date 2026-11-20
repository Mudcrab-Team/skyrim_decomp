// Source exposure: binary-analysis; no external implementation source reused.
// Static174f810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f810*);
    virtual void release(Static174f810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f810*);
struct Static174f810 {
    void* value;
    Static174f810();
    ~Static174f810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
