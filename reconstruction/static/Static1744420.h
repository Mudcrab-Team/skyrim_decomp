// Source exposure: binary-analysis; no external implementation source reused.
// Static1744420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744420*);
    virtual void release(Static1744420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744420*);
struct Static1744420 {
    void* value;
    Static1744420();
    ~Static1744420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
