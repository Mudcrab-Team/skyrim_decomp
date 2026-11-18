// Source exposure: binary-analysis; no external implementation source reused.
// Static1770790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770790*);
    virtual void release(Static1770790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770790*);
struct Static1770790 {
    void* value;
    Static1770790();
    ~Static1770790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
