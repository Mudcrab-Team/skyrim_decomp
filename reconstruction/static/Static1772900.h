// Source exposure: binary-analysis; no external implementation source reused.
// Static1772900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772900*);
    virtual void release(Static1772900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772900*);
struct Static1772900 {
    void* value;
    Static1772900();
    ~Static1772900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
