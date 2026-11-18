// Source exposure: binary-analysis; no external implementation source reused.
// Static1784790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784790*);
    virtual void release(Static1784790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784790*);
struct Static1784790 {
    void* value;
    Static1784790();
    ~Static1784790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
