// Source exposure: binary-analysis; no external implementation source reused.
// Static1764940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764940*);
    virtual void release(Static1764940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764940*);
struct Static1764940 {
    void* value;
    Static1764940();
    ~Static1764940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
