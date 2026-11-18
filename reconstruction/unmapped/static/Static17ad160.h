// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad160*);
    virtual void release(Static17ad160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad160*);
struct Static17ad160 {
    void* value;
    Static17ad160();
    ~Static17ad160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
