// Source exposure: binary-analysis; no external implementation source reused.
// Static1782990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782990*);
    virtual void release(Static1782990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782990*);
struct Static1782990 {
    void* value;
    Static1782990();
    ~Static1782990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
