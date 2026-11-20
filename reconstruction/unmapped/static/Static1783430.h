// Source exposure: binary-analysis; no external implementation source reused.
// Static1783430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783430*);
    virtual void release(Static1783430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783430*);
struct Static1783430 {
    void* value;
    Static1783430();
    ~Static1783430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
