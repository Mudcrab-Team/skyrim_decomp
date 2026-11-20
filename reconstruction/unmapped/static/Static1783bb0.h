// Source exposure: binary-analysis; no external implementation source reused.
// Static1783bb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783bb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783bb0*);
    virtual void release(Static1783bb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783bb0*);
struct Static1783bb0 {
    void* value;
    Static1783bb0();
    ~Static1783bb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
