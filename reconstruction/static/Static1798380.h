// Source exposure: binary-analysis; no external implementation source reused.
// Static1798380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798380*);
    virtual void release(Static1798380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798380*);
struct Static1798380 {
    void* value;
    Static1798380();
    ~Static1798380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
