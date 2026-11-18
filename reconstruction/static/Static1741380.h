// Source exposure: binary-analysis; no external implementation source reused.
// Static1741380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741380*);
    virtual void release(Static1741380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741380*);
struct Static1741380 {
    void* value;
    Static1741380();
    ~Static1741380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
