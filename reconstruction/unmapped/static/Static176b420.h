// Source exposure: binary-analysis; no external implementation source reused.
// Static176b420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b420*);
    virtual void release(Static176b420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b420*);
struct Static176b420 {
    void* value;
    Static176b420();
    ~Static176b420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
