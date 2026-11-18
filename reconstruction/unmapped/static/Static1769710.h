// Source exposure: binary-analysis; no external implementation source reused.
// Static1769710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769710*);
    virtual void release(Static1769710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769710*);
struct Static1769710 {
    void* value;
    Static1769710();
    ~Static1769710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
