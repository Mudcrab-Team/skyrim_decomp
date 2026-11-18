// Source exposure: binary-analysis; no external implementation source reused.
// Static177a420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a420*);
    virtual void release(Static177a420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a420*);
struct Static177a420 {
    void* value;
    Static177a420();
    ~Static177a420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
