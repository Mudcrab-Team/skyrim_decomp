// Source exposure: binary-analysis; no external implementation source reused.
// Static1741470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741470*);
    virtual void release(Static1741470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741470*);
struct Static1741470 {
    void* value;
    Static1741470();
    ~Static1741470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
