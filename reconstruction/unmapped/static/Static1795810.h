// Source exposure: binary-analysis; no external implementation source reused.
// Static1795810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795810*);
    virtual void release(Static1795810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795810*);
struct Static1795810 {
    void* value;
    Static1795810();
    ~Static1795810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
