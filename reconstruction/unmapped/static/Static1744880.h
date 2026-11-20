// Source exposure: binary-analysis; no external implementation source reused.
// Static1744880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744880*);
    virtual void release(Static1744880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744880*);
struct Static1744880 {
    void* value;
    Static1744880();
    ~Static1744880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
