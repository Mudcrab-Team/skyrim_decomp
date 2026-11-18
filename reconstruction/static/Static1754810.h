// Source exposure: binary-analysis; no external implementation source reused.
// Static1754810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754810*);
    virtual void release(Static1754810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754810*);
struct Static1754810 {
    void* value;
    Static1754810();
    ~Static1754810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
