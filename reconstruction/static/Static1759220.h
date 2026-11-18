// Source exposure: binary-analysis; no external implementation source reused.
// Static1759220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759220*);
    virtual void release(Static1759220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759220*);
struct Static1759220 {
    void* value;
    Static1759220();
    ~Static1759220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
