// Source exposure: binary-analysis; no external implementation source reused.
// Static1757420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757420*);
    virtual void release(Static1757420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757420*);
struct Static1757420 {
    void* value;
    Static1757420();
    ~Static1757420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
