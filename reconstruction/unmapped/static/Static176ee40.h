// Source exposure: binary-analysis; no external implementation source reused.
// Static176ee40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ee40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ee40*);
    virtual void release(Static176ee40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ee40*);
struct Static176ee40 {
    void* value;
    Static176ee40();
    ~Static176ee40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
