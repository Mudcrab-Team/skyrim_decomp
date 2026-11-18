// Source exposure: binary-analysis; no external implementation source reused.
// Static175c420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c420*);
    virtual void release(Static175c420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c420*);
struct Static175c420 {
    void* value;
    Static175c420();
    ~Static175c420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
