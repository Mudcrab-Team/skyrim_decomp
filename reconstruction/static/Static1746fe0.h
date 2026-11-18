// Source exposure: binary-analysis; no external implementation source reused.
// Static1746fe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746fe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746fe0*);
    virtual void release(Static1746fe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746fe0*);
struct Static1746fe0 {
    void* value;
    Static1746fe0();
    ~Static1746fe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
