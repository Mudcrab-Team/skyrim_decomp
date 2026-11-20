// Source exposure: binary-analysis; no external implementation source reused.
// Static1760980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760980*);
    virtual void release(Static1760980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760980*);
struct Static1760980 {
    void* value;
    Static1760980();
    ~Static1760980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
