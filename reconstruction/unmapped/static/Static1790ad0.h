// Source exposure: binary-analysis; no external implementation source reused.
// Static1790ad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790ad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790ad0*);
    virtual void release(Static1790ad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790ad0*);
struct Static1790ad0 {
    void* value;
    Static1790ad0();
    ~Static1790ad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
