// Source exposure: binary-analysis; no external implementation source reused.
// Static1795900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795900*);
    virtual void release(Static1795900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795900*);
struct Static1795900 {
    void* value;
    Static1795900();
    ~Static1795900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
