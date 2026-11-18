// Source exposure: binary-analysis; no external implementation source reused.
// Static1764440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764440*);
    virtual void release(Static1764440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764440*);
struct Static1764440 {
    void* value;
    Static1764440();
    ~Static1764440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
