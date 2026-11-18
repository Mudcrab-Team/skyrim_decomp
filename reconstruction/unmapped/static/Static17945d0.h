// Source exposure: binary-analysis; no external implementation source reused.
// Static17945d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17945d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17945d0*);
    virtual void release(Static17945d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17945d0*);
struct Static17945d0 {
    void* value;
    Static17945d0();
    ~Static17945d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
