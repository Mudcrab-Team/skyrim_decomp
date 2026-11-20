// Source exposure: binary-analysis; no external implementation source reused.
// Static1778800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778800*);
    virtual void release(Static1778800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778800*);
struct Static1778800 {
    void* value;
    Static1778800();
    ~Static1778800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
