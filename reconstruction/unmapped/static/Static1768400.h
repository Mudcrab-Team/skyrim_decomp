// Source exposure: binary-analysis; no external implementation source reused.
// Static1768400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768400*);
    virtual void release(Static1768400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768400*);
struct Static1768400 {
    void* value;
    Static1768400();
    ~Static1768400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
