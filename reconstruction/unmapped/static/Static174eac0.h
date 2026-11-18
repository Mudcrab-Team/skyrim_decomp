// Source exposure: binary-analysis; no external implementation source reused.
// Static174eac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eac0*);
    virtual void release(Static174eac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eac0*);
struct Static174eac0 {
    void* value;
    Static174eac0();
    ~Static174eac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
