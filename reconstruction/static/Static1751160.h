// Source exposure: binary-analysis; no external implementation source reused.
// Static1751160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751160*);
    virtual void release(Static1751160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751160*);
struct Static1751160 {
    void* value;
    Static1751160();
    ~Static1751160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
