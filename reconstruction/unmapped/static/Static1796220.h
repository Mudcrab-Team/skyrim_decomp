// Source exposure: binary-analysis; no external implementation source reused.
// Static1796220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796220*);
    virtual void release(Static1796220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796220*);
struct Static1796220 {
    void* value;
    Static1796220();
    ~Static1796220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
