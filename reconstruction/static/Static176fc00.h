// Source exposure: binary-analysis; no external implementation source reused.
// Static176fc00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fc00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fc00*);
    virtual void release(Static176fc00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fc00*);
struct Static176fc00 {
    void* value;
    Static176fc00();
    ~Static176fc00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
