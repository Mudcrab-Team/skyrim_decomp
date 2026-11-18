// Source exposure: binary-analysis; no external implementation source reused.
// Static174dcd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dcd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dcd0*);
    virtual void release(Static174dcd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dcd0*);
struct Static174dcd0 {
    void* value;
    Static174dcd0();
    ~Static174dcd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
