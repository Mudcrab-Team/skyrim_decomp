// Source exposure: binary-analysis; no external implementation source reused.
// Static1783020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783020*);
    virtual void release(Static1783020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783020*);
struct Static1783020 {
    void* value;
    Static1783020();
    ~Static1783020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
