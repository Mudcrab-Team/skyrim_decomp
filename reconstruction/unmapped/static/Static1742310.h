// Source exposure: binary-analysis; no external implementation source reused.
// Static1742310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742310*);
    virtual void release(Static1742310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742310*);
struct Static1742310 {
    void* value;
    Static1742310();
    ~Static1742310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
