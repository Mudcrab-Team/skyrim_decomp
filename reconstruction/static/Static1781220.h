// Source exposure: binary-analysis; no external implementation source reused.
// Static1781220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781220*);
    virtual void release(Static1781220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781220*);
struct Static1781220 {
    void* value;
    Static1781220();
    ~Static1781220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
