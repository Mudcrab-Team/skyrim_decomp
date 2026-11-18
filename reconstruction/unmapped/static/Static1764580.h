// Source exposure: binary-analysis; no external implementation source reused.
// Static1764580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764580*);
    virtual void release(Static1764580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764580*);
struct Static1764580 {
    void* value;
    Static1764580();
    ~Static1764580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
