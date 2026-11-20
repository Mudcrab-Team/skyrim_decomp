// Source exposure: binary-analysis; no external implementation source reused.
// Static1772220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772220*);
    virtual void release(Static1772220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772220*);
struct Static1772220 {
    void* value;
    Static1772220();
    ~Static1772220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
