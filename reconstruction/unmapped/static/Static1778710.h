// Source exposure: binary-analysis; no external implementation source reused.
// Static1778710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778710*);
    virtual void release(Static1778710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778710*);
struct Static1778710 {
    void* value;
    Static1778710();
    ~Static1778710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
