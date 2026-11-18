// Source exposure: binary-analysis; no external implementation source reused.
// Static17701f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17701f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17701f0*);
    virtual void release(Static17701f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17701f0*);
struct Static17701f0 {
    void* value;
    Static17701f0();
    ~Static17701f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
