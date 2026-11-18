// Source exposure: binary-analysis; no external implementation source reused.
// Static1754310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754310*);
    virtual void release(Static1754310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754310*);
struct Static1754310 {
    void* value;
    Static1754310();
    ~Static1754310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
