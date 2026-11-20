// Source exposure: binary-analysis; no external implementation source reused.
// Static1764120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764120*);
    virtual void release(Static1764120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764120*);
struct Static1764120 {
    void* value;
    Static1764120();
    ~Static1764120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
