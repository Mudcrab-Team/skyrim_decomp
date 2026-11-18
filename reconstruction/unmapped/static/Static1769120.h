// Source exposure: binary-analysis; no external implementation source reused.
// Static1769120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769120*);
    virtual void release(Static1769120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769120*);
struct Static1769120 {
    void* value;
    Static1769120();
    ~Static1769120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
