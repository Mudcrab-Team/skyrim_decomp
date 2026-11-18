// Source exposure: binary-analysis; no external implementation source reused.
// Static1790660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790660*);
    virtual void release(Static1790660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790660*);
struct Static1790660 {
    void* value;
    Static1790660();
    ~Static1790660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
