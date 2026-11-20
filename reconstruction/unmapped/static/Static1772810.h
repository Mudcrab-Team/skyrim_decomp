// Source exposure: binary-analysis; no external implementation source reused.
// Static1772810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772810*);
    virtual void release(Static1772810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772810*);
struct Static1772810 {
    void* value;
    Static1772810();
    ~Static1772810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
