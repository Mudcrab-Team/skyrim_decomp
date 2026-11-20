// Source exposure: binary-analysis; no external implementation source reused.
// Static1794310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794310*);
    virtual void release(Static1794310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794310*);
struct Static1794310 {
    void* value;
    Static1794310();
    ~Static1794310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
