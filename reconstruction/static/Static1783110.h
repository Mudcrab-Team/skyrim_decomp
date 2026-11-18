// Source exposure: binary-analysis; no external implementation source reused.
// Static1783110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783110*);
    virtual void release(Static1783110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783110*);
struct Static1783110 {
    void* value;
    Static1783110();
    ~Static1783110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
