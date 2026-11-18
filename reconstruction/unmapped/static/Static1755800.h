// Source exposure: binary-analysis; no external implementation source reused.
// Static1755800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755800*);
    virtual void release(Static1755800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755800*);
struct Static1755800 {
    void* value;
    Static1755800();
    ~Static1755800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
