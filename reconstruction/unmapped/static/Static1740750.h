// Source exposure: binary-analysis; no external implementation source reused.
// Static1740750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740750*);
    virtual void release(Static1740750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740750*);
struct Static1740750 {
    void* value;
    Static1740750();
    ~Static1740750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
