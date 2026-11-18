// Source exposure: binary-analysis; no external implementation source reused.
// Static1783980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783980*);
    virtual void release(Static1783980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783980*);
struct Static1783980 {
    void* value;
    Static1783980();
    ~Static1783980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
