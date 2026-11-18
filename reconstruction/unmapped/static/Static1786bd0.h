// Source exposure: binary-analysis; no external implementation source reused.
// Static1786bd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786bd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786bd0*);
    virtual void release(Static1786bd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786bd0*);
struct Static1786bd0 {
    void* value;
    Static1786bd0();
    ~Static1786bd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
