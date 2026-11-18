// Source exposure: binary-analysis; no external implementation source reused.
// Static1759900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759900*);
    virtual void release(Static1759900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759900*);
struct Static1759900 {
    void* value;
    Static1759900();
    ~Static1759900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
