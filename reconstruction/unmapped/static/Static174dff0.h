// Source exposure: binary-analysis; no external implementation source reused.
// Static174dff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dff0*);
    virtual void release(Static174dff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dff0*);
struct Static174dff0 {
    void* value;
    Static174dff0();
    ~Static174dff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
