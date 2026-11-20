// Source exposure: binary-analysis; no external implementation source reused.
// Static1764760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764760*);
    virtual void release(Static1764760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764760*);
struct Static1764760 {
    void* value;
    Static1764760();
    ~Static1764760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
