// Source exposure: binary-analysis; no external implementation source reused.
// Static176fcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fcf0*);
    virtual void release(Static176fcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fcf0*);
struct Static176fcf0 {
    void* value;
    Static176fcf0();
    ~Static176fcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
