// Source exposure: binary-analysis; no external implementation source reused.
// Static1774660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774660*);
    virtual void release(Static1774660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774660*);
struct Static1774660 {
    void* value;
    Static1774660();
    ~Static1774660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
