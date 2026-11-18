// Source exposure: binary-analysis; no external implementation source reused.
// Static1783de0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783de0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783de0*);
    virtual void release(Static1783de0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783de0*);
struct Static1783de0 {
    void* value;
    Static1783de0();
    ~Static1783de0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
