// Source exposure: binary-analysis; no external implementation source reused.
// Static1790220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790220*);
    virtual void release(Static1790220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790220*);
struct Static1790220 {
    void* value;
    Static1790220();
    ~Static1790220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
