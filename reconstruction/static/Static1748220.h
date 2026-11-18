// Source exposure: binary-analysis; no external implementation source reused.
// Static1748220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748220*);
    virtual void release(Static1748220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748220*);
struct Static1748220 {
    void* value;
    Static1748220();
    ~Static1748220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
