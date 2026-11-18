// Source exposure: binary-analysis; no external implementation source reused.
// Static1798790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798790*);
    virtual void release(Static1798790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798790*);
struct Static1798790 {
    void* value;
    Static1798790();
    ~Static1798790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
