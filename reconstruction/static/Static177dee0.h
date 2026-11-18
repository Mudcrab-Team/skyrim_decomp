// Source exposure: binary-analysis; no external implementation source reused.
// Static177dee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dee0*);
    virtual void release(Static177dee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dee0*);
struct Static177dee0 {
    void* value;
    Static177dee0();
    ~Static177dee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
