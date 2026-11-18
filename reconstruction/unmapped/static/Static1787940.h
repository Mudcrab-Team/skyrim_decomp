// Source exposure: binary-analysis; no external implementation source reused.
// Static1787940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787940*);
    virtual void release(Static1787940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787940*);
struct Static1787940 {
    void* value;
    Static1787940();
    ~Static1787940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
