// Source exposure: binary-analysis; no external implementation source reused.
// Static1768040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768040*);
    virtual void release(Static1768040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768040*);
struct Static1768040 {
    void* value;
    Static1768040();
    ~Static1768040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
