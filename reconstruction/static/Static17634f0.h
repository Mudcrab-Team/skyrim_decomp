// Source exposure: binary-analysis; no external implementation source reused.
// Static17634f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17634f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17634f0*);
    virtual void release(Static17634f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17634f0*);
struct Static17634f0 {
    void* value;
    Static17634f0();
    ~Static17634f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
