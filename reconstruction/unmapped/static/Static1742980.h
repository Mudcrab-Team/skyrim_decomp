// Source exposure: binary-analysis; no external implementation source reused.
// Static1742980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742980*);
    virtual void release(Static1742980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742980*);
struct Static1742980 {
    void* value;
    Static1742980();
    ~Static1742980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
