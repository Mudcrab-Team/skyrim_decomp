// Source exposure: binary-analysis; no external implementation source reused.
// Static1782800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782800*);
    virtual void release(Static1782800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782800*);
struct Static1782800 {
    void* value;
    Static1782800();
    ~Static1782800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
