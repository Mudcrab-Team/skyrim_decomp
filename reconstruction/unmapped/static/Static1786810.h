// Source exposure: binary-analysis; no external implementation source reused.
// Static1786810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786810*);
    virtual void release(Static1786810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786810*);
struct Static1786810 {
    void* value;
    Static1786810();
    ~Static1786810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
