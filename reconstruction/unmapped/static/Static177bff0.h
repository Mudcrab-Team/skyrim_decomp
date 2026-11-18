// Source exposure: binary-analysis; no external implementation source reused.
// Static177bff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bff0*);
    virtual void release(Static177bff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bff0*);
struct Static177bff0 {
    void* value;
    Static177bff0();
    ~Static177bff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
