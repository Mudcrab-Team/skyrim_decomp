// Source exposure: binary-analysis; no external implementation source reused.
// Static1772ae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772ae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772ae0*);
    virtual void release(Static1772ae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772ae0*);
struct Static1772ae0 {
    void* value;
    Static1772ae0();
    ~Static1772ae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
