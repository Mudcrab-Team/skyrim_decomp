// Source exposure: binary-analysis; no external implementation source reused.
// Static1775100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775100*);
    virtual void release(Static1775100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775100*);
struct Static1775100 {
    void* value;
    Static1775100();
    ~Static1775100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
