// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6420*);
    virtual void release(Static17b6420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6420*);
struct Static17b6420 {
    void* value;
    Static17b6420();
    ~Static17b6420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
