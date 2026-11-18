// Source exposure: binary-analysis; no external implementation source reused.
// Static173eec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173eec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173eec0*);
    virtual void release(Static173eec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173eec0*);
struct Static173eec0 {
    void* value;
    Static173eec0();
    ~Static173eec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
