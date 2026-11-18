// Source exposure: binary-analysis; no external implementation source reused.
// Static1797330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797330*);
    virtual void release(Static1797330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797330*);
struct Static1797330 {
    void* value;
    Static1797330();
    ~Static1797330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
