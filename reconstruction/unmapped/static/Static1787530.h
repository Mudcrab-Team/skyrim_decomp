// Source exposure: binary-analysis; no external implementation source reused.
// Static1787530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787530*);
    virtual void release(Static1787530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787530*);
struct Static1787530 {
    void* value;
    Static1787530();
    ~Static1787530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
