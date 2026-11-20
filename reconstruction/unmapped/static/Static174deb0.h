// Source exposure: binary-analysis; no external implementation source reused.
// Static174deb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174deb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174deb0*);
    virtual void release(Static174deb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174deb0*);
struct Static174deb0 {
    void* value;
    Static174deb0();
    ~Static174deb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
