// Source exposure: binary-analysis; no external implementation source reused.
// Static1747250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747250*);
    virtual void release(Static1747250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747250*);
struct Static1747250 {
    void* value;
    Static1747250();
    ~Static1747250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
