// Source exposure: binary-analysis; no external implementation source reused.
// Static1784600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784600*);
    virtual void release(Static1784600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784600*);
struct Static1784600 {
    void* value;
    Static1784600();
    ~Static1784600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
