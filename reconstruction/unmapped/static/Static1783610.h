// Source exposure: binary-analysis; no external implementation source reused.
// Static1783610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783610*);
    virtual void release(Static1783610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783610*);
struct Static1783610 {
    void* value;
    Static1783610();
    ~Static1783610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
