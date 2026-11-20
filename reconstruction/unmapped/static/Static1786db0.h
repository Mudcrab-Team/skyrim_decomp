// Source exposure: binary-analysis; no external implementation source reused.
// Static1786db0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786db0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786db0*);
    virtual void release(Static1786db0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786db0*);
struct Static1786db0 {
    void* value;
    Static1786db0();
    ~Static1786db0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
