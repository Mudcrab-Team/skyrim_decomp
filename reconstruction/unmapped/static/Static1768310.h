// Source exposure: binary-analysis; no external implementation source reused.
// Static1768310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768310*);
    virtual void release(Static1768310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768310*);
struct Static1768310 {
    void* value;
    Static1768310();
    ~Static1768310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
