// Source exposure: binary-analysis; no external implementation source reused.
// Static1754f90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754f90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754f90*);
    virtual void release(Static1754f90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754f90*);
struct Static1754f90 {
    void* value;
    Static1754f90();
    ~Static1754f90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
