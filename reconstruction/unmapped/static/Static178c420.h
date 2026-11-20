// Source exposure: binary-analysis; no external implementation source reused.
// Static178c420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c420*);
    virtual void release(Static178c420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c420*);
struct Static178c420 {
    void* value;
    Static178c420();
    ~Static178c420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
