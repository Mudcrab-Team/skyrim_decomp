// Source exposure: binary-analysis; no external implementation source reused.
// Static1770420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770420*);
    virtual void release(Static1770420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770420*);
struct Static1770420 {
    void* value;
    Static1770420();
    ~Static1770420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
