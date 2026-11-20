// Source exposure: binary-analysis; no external implementation source reused.
// Static173d420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d420*);
    virtual void release(Static173d420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d420*);
struct Static173d420 {
    void* value;
    Static173d420();
    ~Static173d420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
