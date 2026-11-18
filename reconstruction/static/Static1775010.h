// Source exposure: binary-analysis; no external implementation source reused.
// Static1775010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775010*);
    virtual void release(Static1775010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775010*);
struct Static1775010 {
    void* value;
    Static1775010();
    ~Static1775010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
