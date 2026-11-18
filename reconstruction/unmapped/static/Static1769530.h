// Source exposure: binary-analysis; no external implementation source reused.
// Static1769530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769530*);
    virtual void release(Static1769530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769530*);
struct Static1769530 {
    void* value;
    Static1769530();
    ~Static1769530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
