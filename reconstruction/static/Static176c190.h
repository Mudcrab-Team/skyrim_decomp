// Source exposure: binary-analysis; no external implementation source reused.
// Static176c190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c190*);
    virtual void release(Static176c190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c190*);
struct Static176c190 {
    void* value;
    Static176c190();
    ~Static176c190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
