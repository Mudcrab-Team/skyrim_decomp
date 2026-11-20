// Source exposure: binary-analysis; no external implementation source reused.
// Static1772310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772310*);
    virtual void release(Static1772310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772310*);
struct Static1772310 {
    void* value;
    Static1772310();
    ~Static1772310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
