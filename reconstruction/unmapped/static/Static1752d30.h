// Source exposure: binary-analysis; no external implementation source reused.
// Static1752d30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752d30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752d30*);
    virtual void release(Static1752d30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752d30*);
struct Static1752d30 {
    void* value;
    Static1752d30();
    ~Static1752d30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
