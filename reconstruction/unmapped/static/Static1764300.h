// Source exposure: binary-analysis; no external implementation source reused.
// Static1764300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764300*);
    virtual void release(Static1764300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764300*);
struct Static1764300 {
    void* value;
    Static1764300();
    ~Static1764300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
