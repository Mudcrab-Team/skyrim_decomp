// Source exposure: binary-analysis; no external implementation source reused.
// Static1778fd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778fd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778fd0*);
    virtual void release(Static1778fd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778fd0*);
struct Static1778fd0 {
    void* value;
    Static1778fd0();
    ~Static1778fd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
