// Source exposure: binary-analysis; no external implementation source reused.
// Static1764800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764800*);
    virtual void release(Static1764800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764800*);
struct Static1764800 {
    void* value;
    Static1764800();
    ~Static1764800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
