// Source exposure: binary-analysis; no external implementation source reused.
// Static1790cd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790cd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790cd0*);
    virtual void release(Static1790cd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790cd0*);
struct Static1790cd0 {
    void* value;
    Static1790cd0();
    ~Static1790cd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
