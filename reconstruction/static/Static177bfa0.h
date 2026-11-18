// Source exposure: binary-analysis; no external implementation source reused.
// Static177bfa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bfa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bfa0*);
    virtual void release(Static177bfa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bfa0*);
struct Static177bfa0 {
    void* value;
    Static177bfa0();
    ~Static177bfa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
