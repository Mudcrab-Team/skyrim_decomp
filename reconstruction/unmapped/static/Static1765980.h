// Source exposure: binary-analysis; no external implementation source reused.
// Static1765980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765980*);
    virtual void release(Static1765980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765980*);
struct Static1765980 {
    void* value;
    Static1765980();
    ~Static1765980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
