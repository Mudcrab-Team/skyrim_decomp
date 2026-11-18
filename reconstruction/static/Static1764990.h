// Source exposure: binary-analysis; no external implementation source reused.
// Static1764990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764990*);
    virtual void release(Static1764990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764990*);
struct Static1764990 {
    void* value;
    Static1764990();
    ~Static1764990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
