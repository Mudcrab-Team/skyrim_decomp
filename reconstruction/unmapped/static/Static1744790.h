// Source exposure: binary-analysis; no external implementation source reused.
// Static1744790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744790*);
    virtual void release(Static1744790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744790*);
struct Static1744790 {
    void* value;
    Static1744790();
    ~Static1744790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
