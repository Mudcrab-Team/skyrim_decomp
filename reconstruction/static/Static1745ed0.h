// Source exposure: binary-analysis; no external implementation source reused.
// Static1745ed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1745ed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1745ed0*);
    virtual void release(Static1745ed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1745ed0*);
struct Static1745ed0 {
    void* value;
    Static1745ed0();
    ~Static1745ed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
