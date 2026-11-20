// Source exposure: binary-analysis; no external implementation source reused.
// Static1783660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783660*);
    virtual void release(Static1783660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783660*);
struct Static1783660 {
    void* value;
    Static1783660();
    ~Static1783660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
