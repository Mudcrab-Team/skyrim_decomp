// Source exposure: binary-analysis; no external implementation source reused.
// Static17954c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17954c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17954c0*);
    virtual void release(Static17954c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17954c0*);
struct Static17954c0 {
    void* value;
    Static17954c0();
    ~Static17954c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
