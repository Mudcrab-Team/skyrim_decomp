// Source exposure: binary-analysis; no external implementation source reused.
// Static1789b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789b70*);
    virtual void release(Static1789b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789b70*);
struct Static1789b70 {
    void* value;
    Static1789b70();
    ~Static1789b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
