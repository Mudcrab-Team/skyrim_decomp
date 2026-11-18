// Source exposure: binary-analysis; no external implementation source reused.
// Static1756660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756660*);
    virtual void release(Static1756660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756660*);
struct Static1756660 {
    void* value;
    Static1756660();
    ~Static1756660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
