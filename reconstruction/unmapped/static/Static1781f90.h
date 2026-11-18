// Source exposure: binary-analysis; no external implementation source reused.
// Static1781f90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781f90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781f90*);
    virtual void release(Static1781f90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781f90*);
struct Static1781f90 {
    void* value;
    Static1781f90();
    ~Static1781f90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
