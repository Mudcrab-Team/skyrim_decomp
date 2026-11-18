// Source exposure: binary-analysis; no external implementation source reused.
// Static1744c40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744c40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744c40*);
    virtual void release(Static1744c40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744c40*);
struct Static1744c40 {
    void* value;
    Static1744c40();
    ~Static1744c40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
