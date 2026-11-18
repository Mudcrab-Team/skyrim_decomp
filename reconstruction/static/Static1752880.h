// Source exposure: binary-analysis; no external implementation source reused.
// Static1752880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752880*);
    virtual void release(Static1752880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752880*);
struct Static1752880 {
    void* value;
    Static1752880();
    ~Static1752880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
