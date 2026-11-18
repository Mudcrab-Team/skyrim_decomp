// Source exposure: binary-analysis; no external implementation source reused.
// Static174ddc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ddc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ddc0*);
    virtual void release(Static174ddc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ddc0*);
struct Static174ddc0 {
    void* value;
    Static174ddc0();
    ~Static174ddc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
