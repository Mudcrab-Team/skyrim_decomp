// Source exposure: binary-analysis; no external implementation source reused.
// Static1783750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783750*);
    virtual void release(Static1783750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783750*);
struct Static1783750 {
    void* value;
    Static1783750();
    ~Static1783750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
