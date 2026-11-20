// Source exposure: binary-analysis; no external implementation source reused.
// Static17841f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17841f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17841f0*);
    virtual void release(Static17841f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17841f0*);
struct Static17841f0 {
    void* value;
    Static17841f0();
    ~Static17841f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
