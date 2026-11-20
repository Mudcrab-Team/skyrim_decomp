// Source exposure: binary-analysis; no external implementation source reused.
// Static1741000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741000*);
    virtual void release(Static1741000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741000*);
struct Static1741000 {
    void* value;
    Static1741000();
    ~Static1741000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
