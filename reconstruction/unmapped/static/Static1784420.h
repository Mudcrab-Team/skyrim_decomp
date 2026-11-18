// Source exposure: binary-analysis; no external implementation source reused.
// Static1784420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784420*);
    virtual void release(Static1784420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784420*);
struct Static1784420 {
    void* value;
    Static1784420();
    ~Static1784420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
