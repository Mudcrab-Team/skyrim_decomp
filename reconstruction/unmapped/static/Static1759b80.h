// Source exposure: binary-analysis; no external implementation source reused.
// Static1759b80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759b80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759b80*);
    virtual void release(Static1759b80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759b80*);
struct Static1759b80 {
    void* value;
    Static1759b80();
    ~Static1759b80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
