// Source exposure: binary-analysis; no external implementation source reused.
// Static1782ad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782ad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782ad0*);
    virtual void release(Static1782ad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782ad0*);
struct Static1782ad0 {
    void* value;
    Static1782ad0();
    ~Static1782ad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
