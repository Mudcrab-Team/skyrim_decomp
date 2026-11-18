// Source exposure: binary-analysis; no external implementation source reused.
// Static1783b10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783b10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783b10*);
    virtual void release(Static1783b10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783b10*);
struct Static1783b10 {
    void* value;
    Static1783b10();
    ~Static1783b10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
