// Source exposure: binary-analysis; no external implementation source reused.
// Static174d4e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d4e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d4e0*);
    virtual void release(Static174d4e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d4e0*);
struct Static174d4e0 {
    void* value;
    Static174d4e0();
    ~Static174d4e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
