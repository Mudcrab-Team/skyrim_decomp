// Source exposure: binary-analysis; no external implementation source reused.
// Static1788660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788660*);
    virtual void release(Static1788660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788660*);
struct Static1788660 {
    void* value;
    Static1788660();
    ~Static1788660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
