// Source exposure: binary-analysis; no external implementation source reused.
// Static1769260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769260*);
    virtual void release(Static1769260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769260*);
struct Static1769260 {
    void* value;
    Static1769260();
    ~Static1769260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
