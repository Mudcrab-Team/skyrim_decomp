// Source exposure: binary-analysis; no external implementation source reused.
// Static174eea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eea0*);
    virtual void release(Static174eea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eea0*);
struct Static174eea0 {
    void* value;
    Static174eea0();
    ~Static174eea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
