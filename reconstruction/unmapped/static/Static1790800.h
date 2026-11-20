// Source exposure: binary-analysis; no external implementation source reused.
// Static1790800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790800*);
    virtual void release(Static1790800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790800*);
struct Static1790800 {
    void* value;
    Static1790800();
    ~Static1790800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
