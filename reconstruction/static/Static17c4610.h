// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4610*);
    virtual void release(Static17c4610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4610*);
struct Static17c4610 {
    void* value;
    Static17c4610();
    ~Static17c4610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
