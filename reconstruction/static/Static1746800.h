// Source exposure: binary-analysis; no external implementation source reused.
// Static1746800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746800*);
    virtual void release(Static1746800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746800*);
struct Static1746800 {
    void* value;
    Static1746800();
    ~Static1746800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
