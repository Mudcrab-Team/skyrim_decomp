// Source exposure: binary-analysis; no external implementation source reused.
// Static1764350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764350*);
    virtual void release(Static1764350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764350*);
struct Static1764350 {
    void* value;
    Static1764350();
    ~Static1764350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
