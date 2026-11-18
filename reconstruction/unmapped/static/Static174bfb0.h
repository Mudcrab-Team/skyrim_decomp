// Source exposure: binary-analysis; no external implementation source reused.
// Static174bfb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bfb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bfb0*);
    virtual void release(Static174bfb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bfb0*);
struct Static174bfb0 {
    void* value;
    Static174bfb0();
    ~Static174bfb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
