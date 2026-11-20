// Source exposure: binary-analysis; no external implementation source reused.
// Static1777f90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777f90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777f90*);
    virtual void release(Static1777f90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777f90*);
struct Static1777f90 {
    void* value;
    Static1777f90();
    ~Static1777f90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
