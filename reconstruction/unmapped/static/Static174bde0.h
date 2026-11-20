// Source exposure: binary-analysis; no external implementation source reused.
// Static174bde0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bde0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bde0*);
    virtual void release(Static174bde0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bde0*);
struct Static174bde0 {
    void* value;
    Static174bde0();
    ~Static174bde0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
