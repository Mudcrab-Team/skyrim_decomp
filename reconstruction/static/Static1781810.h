// Source exposure: binary-analysis; no external implementation source reused.
// Static1781810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781810*);
    virtual void release(Static1781810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781810*);
struct Static1781810 {
    void* value;
    Static1781810();
    ~Static1781810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
