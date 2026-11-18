// Source exposure: binary-analysis; no external implementation source reused.
// Static1749800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749800*);
    virtual void release(Static1749800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749800*);
struct Static1749800 {
    void* value;
    Static1749800();
    ~Static1749800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
