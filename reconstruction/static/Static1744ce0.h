// Source exposure: binary-analysis; no external implementation source reused.
// Static1744ce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744ce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744ce0*);
    virtual void release(Static1744ce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744ce0*);
struct Static1744ce0 {
    void* value;
    Static1744ce0();
    ~Static1744ce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
