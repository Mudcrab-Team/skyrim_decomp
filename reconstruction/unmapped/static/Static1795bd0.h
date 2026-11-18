// Source exposure: binary-analysis; no external implementation source reused.
// Static1795bd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795bd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795bd0*);
    virtual void release(Static1795bd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795bd0*);
struct Static1795bd0 {
    void* value;
    Static1795bd0();
    ~Static1795bd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
