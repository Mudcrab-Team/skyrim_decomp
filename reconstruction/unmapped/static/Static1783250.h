// Source exposure: binary-analysis; no external implementation source reused.
// Static1783250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783250*);
    virtual void release(Static1783250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783250*);
struct Static1783250 {
    void* value;
    Static1783250();
    ~Static1783250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
