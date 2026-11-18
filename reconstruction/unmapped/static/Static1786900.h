// Source exposure: binary-analysis; no external implementation source reused.
// Static1786900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786900*);
    virtual void release(Static1786900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786900*);
struct Static1786900 {
    void* value;
    Static1786900();
    ~Static1786900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
