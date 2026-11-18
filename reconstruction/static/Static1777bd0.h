// Source exposure: binary-analysis; no external implementation source reused.
// Static1777bd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777bd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777bd0*);
    virtual void release(Static1777bd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777bd0*);
struct Static1777bd0 {
    void* value;
    Static1777bd0();
    ~Static1777bd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
