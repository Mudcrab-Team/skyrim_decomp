// Source exposure: binary-analysis; no external implementation source reused.
// Static1789800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789800*);
    virtual void release(Static1789800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789800*);
struct Static1789800 {
    void* value;
    Static1789800();
    ~Static1789800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
