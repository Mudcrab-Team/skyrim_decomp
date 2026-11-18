// Source exposure: binary-analysis; no external implementation source reused.
// Static1783930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783930*);
    virtual void release(Static1783930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783930*);
struct Static1783930 {
    void* value;
    Static1783930();
    ~Static1783930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
