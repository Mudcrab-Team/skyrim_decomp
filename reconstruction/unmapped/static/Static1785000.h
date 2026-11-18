// Source exposure: binary-analysis; no external implementation source reused.
// Static1785000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785000*);
    virtual void release(Static1785000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785000*);
struct Static1785000 {
    void* value;
    Static1785000();
    ~Static1785000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
